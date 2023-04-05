/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:33:19 by micarrel          #+#    #+#             */
/*   Updated: 2023/04/05 16:19:15 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_img(t_image image, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx,
		image.path, &image.img_width, &image.img_heigth);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.window, image.img, x, y);
	return (image.img);
}

t_block	witch_block(char name)
{
	t_block	map[6];
	int i;

	map[0] = (t_block){"0", "./img/floor.xpm"};
	map[1] = (t_block){"1", "./img/water.xpm"};
	map[2] = (t_block){"C", "./img/plant.xpm"};
	map[3] = (t_block){"P", "./img/down.xpm"};
	map[4] = (t_block){"E", "./img/exit.xpm"};
	map[5] = (t_block){NULL, NULL};
	i = 0;
	while (map[i].name != NULL)
	{
		if (map[i].name[0] == name)
		{
			return (map[i]);
			break ;
		}
		i++;
	}
	return (map[5]);
}