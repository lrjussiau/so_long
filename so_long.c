/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:11:25 by ljussiau          #+#    #+#             */
/*   Updated: 2023/12/14 08:04:20 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

// void	ft_print_map(char **tab)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		j = -1;
// 		while (tab[i][++j])
// 			write(1, &tab[i][j], 1);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }

void	you_win(t_mlx_data *data)
{
	ft_putstr_fd("You win !\n You made it with ", 1);
	ft_putnbr_fd(data->nb_action, 1);
	ft_putstr_fd(" moves\n", 1);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	you_lose(t_mlx_data *data)
{
	ft_putstr_fd("You Lose !\n You have been catched after ", 1);
	ft_putnbr_fd(data->nb_action, 1);
	ft_putstr_fd(" moves\n", 1);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	close_game(t_mlx_data *data)
{
	ft_putstr_fd("You Quit the game ! Bye", 1);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	print_nb_move(t_mlx_data *data)
{
	char	*nb_move;
	int		text_color;

	text_color = 0x000000;
	nb_move = ft_itoa(data -> nb_action);
	mlx_string_put(data->mlx, data->win, 27, 27, text_color, nb_move);
	free(nb_move);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	t_point		s;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong input, insert the map path.\n", 1);
		return (1);
	}
	data.nb_action = 0;
	data.area = create_map(argv[1]);
	if (data.area == NULL)
		return (0);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	s = get_size(data.area);
	data.win = mlx_new_window(data.mlx, (s.x + 1) * 64, (s.y + 1) * 64, "Pk");
	if (data.win == NULL)
		close_game(&data);
	ft_print_area(data.area, data, 'b', 'b');
	mlx_key_hook(data.win, handle_input, &data);
	mlx_hook(data.win, DESTROY_NOTIFY, 0, close_game, &data);
	mlx_loop_hook(data.mlx, print_nb_move, &data);
	mlx_loop(data.mlx);
}
