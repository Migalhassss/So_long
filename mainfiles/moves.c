/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:00:30 by micarrel          #+#    #+#             */
/*   Updated: 2023/04/05 16:12:01 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_game *game, int x, int y)
{
	t_image img;
	
	img.path = "./img/floor.xpm";
	img.wlx = *game;
	put_img(img, game->player.x, game->player.y);
	put_img(img, x, y);
}

void	ft_up(t_game *game)
{
	int		i;
	int		j;
	t_image	img;

	img.path = "./img/up.xpm";
	img.wlx = *game;
	i = game->player.y - 64;
	j = game->player.x;
	if ((check_move(game, (i / 64), (j / 64)) != 1))
	{
		game->player.move++;
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_img(img, j, i);
	}
}

void	ft_down(t_game *game)
{
	int		i;
	int		j;
	t_image	img;
	
	img.path = "./img/down.xpm";
	img.wlx = *game;
	i = game->player.y + 64;
	j = game->player.x;
	if ((check_move(game, (i / 64), (j / 64)) != 1))
	{
		game->player.move++;
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_img(img, j, i);
	}
}

void	ft_left(t_game *game)
{
	int		i;
	int		j;
	t_image	img;

	img.path = "./img/left.xpm";
	img.wlx = *game;
	i = game->player.y;
	j = game->player.x - 64;
	if ((check_move(game, (i / 64), (j / 64)) != 1))
	{
		game->player.move++;
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_img(img, j, i);
	}
}

void	ft_right(t_game *game)
{
	int		i;
	int		j;
	t_image	img;

	img.path = "./img/right.xpm";
	img.wlx = *game;
	i = game->player.y;
	j = game->player.x + 64;
	if ((check_move(game, (i / 64), (j / 64)) != 1))
	{
		game->player.move++;
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_img(img, j, i);
	}
}