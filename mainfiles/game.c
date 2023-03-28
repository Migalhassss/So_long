/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:39:05 by micarrel          #+#    #+#             */
/*   Updated: 2023/03/28 15:16:04 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_game *game)
{
	int	i;
	i = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
}

int	window_destroy(t_game *game)
{
	mlx_destroy_window(game->mlxm game->window);
	destroy_map(game);
	exit(0)l
}

void	control_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j++;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exitcheck++;
			j++;
		}
		i++;
	}
	if (game->exitcheck == 0)
		ft_error("Error\n", game);
	if (game->coincheck == 0)
		ft_error("Error\n", game);
	if (game->playercheck != 1)
		ft_error("Error\n", game);
		
}

void	control_wall(t_game *game)
{
	size_t	x;
	int	y;

	y = 0;
	while (x < (game->size_x / 48))
	{
		if ((y == 0 || x == 0) && game->map[y][x] != '1')
			ft_error("Error\n", game);
		else if ((y == (game->size_y / 48)
				|| x == (game->size_x / 48))
			&& game->map[y][x] != '1')
			ft_error("Error\n", game);
		x++;
	}
	y++;
}

void	control_game(t_game *game)
{
	int	j;
	int	i;
	
	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->coincheck++;
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * 48;
				game->player.y = i * 48;
				game->playercheck++;
			}
			j++;
		}
		i++;
	}
	control_map(game);
	control_wall(game);
}