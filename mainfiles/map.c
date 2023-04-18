/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:22:06 by micarrel          #+#    #+#             */
/*   Updated: 2023/03/14 13:22:06 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_create(t_game *game, int i)
{
	int		j;
	t_image	image;
	t_block	map;

	image.wlx = *game;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			map = witch_block(game->map[i][j]);
			image.path = map.path;
			put_img(game, image, (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	floor_create(t_game *game, int i)
{
	int		j;
	t_image	img;

	img.wlx = *game;
	j = 0;
	if (ft_strlen(game->map[i]) != game->size_x / 64 && i != (game->size_y / 64))
		ft_error("O mapa não é retangular\n", game);
	if (game->map[(game->size_y / 64)] && game->map[(game->size_y / 64)][0] != '\0')
		ft_error("Mapa errado\n", game);
	while (game->map[i])
	{
		j = 0;
		while ((game->map[i][j]))
		{
			if (!ft_strchr("1PCE0", game->map[i][j]))
				ft_error("Error\n", game);
			img.path = "./img/floor.xpm";
			put_img(game ,img, (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	create_maplenght(char *area, t_game *game, int i)
{
	int		j;

	j = 0;
	game->map[i] = (char *)malloc(sizeof(char) * (game->size_x + 1));
	if (game->map[i] == NULL)
		return ;
	while (area[j] > 32)
	{
		if (area[j] == '\n')
			break ;
		game->map[i][j] = area[j];
		j++;
	}
	game->map[i][j] = '\0';
	floor_create(game, i);
	map_create(game, i);
}

void	create_mapline(t_game *game, char **av)
{
	int		fd;
	char	*area;
	int		i;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->size_y + 1));
	if (game->map == NULL)
		return ;
	fd = open(av[1], O_RDONLY);
	while (i < game->size_y)
	{
		game->map[i] = 0;
		i++;
	}
	i = 0;
	while (i < game->size_y / 64)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_maplenght(area, game, i);
		i++;
	}
	close(fd);
}