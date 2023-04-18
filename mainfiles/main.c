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

void	ft_error(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	destroy_map(game);
	exit(1);
}

int	check_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		window_destroy(game);
	if (keycode == 119)
		ft_up(game);
	if (keycode == 97)
		ft_left(game);
	if (keycode == 100)
		ft_right(game);
	if (keycode == 115)
		ft_down(game);
	return (0);
}

void	start(t_game *game)
{
	game->coincheck = 0;
	game->exitcheck = 0;
	game->player.coin = 0;
	game->player.move = 0;
	game->playercheck = 0;
}

int main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	 	return (0);
	ft_window_size(&game, av);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.size_x, game.size_y, "so_long");
	start(&game);
	create_mapline(&game, av);
	control_game(&game);
	mlx_hook(game.window, 2, 1L, check_key, &game);
	mlx_hook(game.window, 17, 1L, window_destroy, &game);
	mlx_loop(game.mlx);
}