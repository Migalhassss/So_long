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
	data->size_y = ft_count_line(fd) * 64;
}

int window_destroy(t_game *game)
{
	// t_image img;

	// img.wlx = *game;
	// mlx_destroy_image(game->mlx, img.path);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	destroy_map(game);
	exit(0);
}