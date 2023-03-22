/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:08:51 by micarrel          #+#    #+#             */
/*   Updated: 2023/03/13 13:08:51 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

// void	ft_error(char *msg, t-_game *game)
// {
// 	ft_printf("%s", msg);
// 	map_destroy(game);
// 	exit(0);
// }

// int	check_key(int keycode, t_game *game)
// {
// 	if (keycode == ESC)
// 		destroy_window(game);
// 	if (keycode == UP)
// 		ft_up(game);
// 	if (keycode == LEFT)
// 		ft_left(game);
// 	if (keycode == RIGHT)
// 		ft_right(game);
// 	if (keycode == DOWN)
// 		ft_down(game);
// 	return (0);
// }

// void	start(t_game *game)
// {
// 	game->coincheck = 0;
// 	game->exitcheck = 0;
// 	game->player.coin = 0;
// 	game->player.hareket = 0;
// 	game->player.movement = 0;
// 	game->playercheck = 0;
// }

void	check_ber_file(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && ft_strcmp(str, ".ber") == 0)
			return ;
		i++;
	}
	exit(0);
}

int main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	 	return (0);
	
	check_ber_file(av[1]);
// 	game.mlx = mlx_init();
// 	game.window = mlx_new_window(game.mlx, game.size_x, game.size_y, "so_long");
// 	start(&game);
// 	create_map_line(&game, argv);
// 	game_control(&game);
// 	mlx_hook(game.window, 17, 1L << 2, mlx_destroy_window, &game);
// 	mlx_loop(game.mlx);
}