/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:08:52 by micarrel          #+#    #+#             */
/*   Updated: 2023/03/13 13:08:52 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_player
{
	int	x;
	int	y;
	int	coin;
	int	move;
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		coincheck;
	int		playercheck;
	int		exitcheck;
	size_t	size_x;
	int		size_y;
	t_player	player;
}	t_game;

typedef struct s_image
{
}	t_image;

typedef struct s_block
{

}	t_blox;



void	ft_window_size(t_game *data, char **argv);

#endif