/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:46:25 by micarrel          #+#    #+#             */
/*   Updated: 2023/03/13 13:46:25 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_game *data, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\n", data);
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
		ft_error("Error\n", data);
	data->size_x = (ft_line(fd) * 64);
	data->size_y = (ft_count_line(fd) * 64);
	if (data->size_x == 0 || data->size_y == 0)
	{
		ft_printf("Mapa vazio\n");
		exit(1);
	}
	else if (data->size_x == (long unsigned int)data->size_y)
	{
		ft_printf("Mapa quadrado\n");
		exit(1);
	}
}

int	window_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	destroy_map(game);
	free(game->mlx);
	exit(1);
}

void	flood_fill(int x, int y, int *flag, char **tab)
{
	if (tab[y][x] == '1' || tab[y][x] == 'P' || tab[y][x] == 'D')
		return ;
	else if (tab[y][x] == '0')
		tab[y][x] = 'P';
	else if (tab[y][x] == 'C')
		tab[y][x] = 'D';
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

void	flood_fill_C(int x, int y, int *flag, char **tab)
{
	if (tab[y][x] == '1' || tab[y][x] == '0' || tab[y][x] == 'E')
		return ;
	else if (tab[y][x] == 'P')
		tab[y][x] = '0';
	else if (tab[y][x] == 'C' || tab[y][x] == 'D')
	{
		(*flag)++;
		tab[y][x] = 'C';
	}
	flood_fill(x + 1, y, flag, tab);
	flood_fill(x - 1, y, flag, tab);
	flood_fill(x, y + 1, flag, tab);
	flood_fill(x, y - 1, flag, tab);
}

void	fill_flood(t_game *game)
{
	int		x;
	int		y;
	int		flag;
	char	**tab;

	flag = 0;
	x = game->player.x;
	y = game->player.y;
	tab = game->map;
	flood_fill(x / 64 + 1, y / 64, &flag, tab);
	flood_fill(x / 64 - 1, y / 64, &flag, tab);
	flood_fill(x / 64, y / 64 - 1, &flag, tab);
	flood_fill(x / 64, y / 64 + 1, &flag, tab);
	flood_fill_C(x / 64 + 1, y / 64, &flag, tab);
	flood_fill_C(x / 64 - 1, y / 64, &flag, tab);
	flood_fill_C(x / 64, y / 64 - 1, &flag, tab);
	flood_fill_C(x / 64, y / 64 + 1, &flag, tab);
	if (flag == 0 || flag != game->coincheck)
		ft_error("Exit Error\n", game);
}
