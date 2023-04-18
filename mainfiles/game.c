/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:39:05 by micarrel          #+#    #+#             */
/*   Updated: 2023/04/18 09:39:20 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
}

void	control_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
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
	int		y;

	y = 0;
	while (y < (game->size_y / 64))
	{
		x = 0;
		while (x < (game->size_x / 64))
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				ft_error("Error\n", game);
			else if ((y == (game->size_y / 64 - 1)
					|| x == (game->size_x / 64 - 1))
				&& game->map[y][x] != '1')
				ft_error("Error\n", game);
			x++;
		}
		y++;
	}
}

void	flood_fill(int x, int y, int *flag, char **tab)
{
	if (tab[y][x] == '1' || tab[y][x] == 'P')
		return ;
	else if(tab[y][x] == '0')
		tab[y][x] = 'P';
	else if (tab[y][x] == 'C')
		tab[y][x] = 'C';
	else if (tab[y][x] == 'E')
	{
		(*flag)++;
		tab[y][x] = 'E';
	}
	flood_fill(x + 1, y, flag, tab);
	flood_fill(x - 1, y, flag, tab);
	flood_fill(x, y + 1, flag, tab);
	flood_fill(x, y - 1, flag, tab);
}

void	control_game(t_game *game)
{
	int	j;
	int	i;
	int	k;
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
				game->player.x = j * 64;
				game->player.y = i * 64;
				game->playercheck++;
			}
			j++;
		}
		i++;
	}
	control_map(game);
	control_wall(game);
	k = 0;
	flood_fill(game->player.x / 64 + 1 , game->player.y / 64, &k, game->map);
	flood_fill(game->player.x / 64 - 1, game->player.y / 64, &k, game->map);
	flood_fill(game->player.x / 64, game->player.y / 64 - 1, &k, game->map);
	flood_fill(game->player.x / 64, game->player.y / 64 + 1, &k, game->map);
	if (k == 0)
		ft_error("Exit Error", game);
}

int	check_move(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'C')
	{
		game->player.coin++;
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coin != game->coincheck)
			return (1);
		window_destroy(game);
	}
	return (0);
}