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

# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_player
{
	int	x;
	int	y;
	int	coin;
	int	move;
}		t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			coincheck;
	int			playercheck;
	int			exitcheck;
	size_t		size_x;
	int			size_y;
	t_player	player;
}				t_game;

typedef struct s_image
{
	struct	s_game	wlx;
	char			*path;
	void			*img;
	int				img_width;
	int				img_heigth;
}					t_image;

typedef struct s_block
{
	char	*name;
	char	*path;
}			t_block;

/*-------------------Game.c-------------------*/
void	destroy_map(t_game *game);
void	control_map(t_game *game);
void	control_wall(t_game *game);
void	control_game(t_game *game);
int		check_move(t_game *game, int i, int j);

/*--------------------------------------------*/


/*-------------------Gnl.c--------------------*/
int		ft_line(int fd);
int		ft_count_line(int fd);
void	*myfree(void *str);
char	*get_next_line(int fd);

/*--------------------------------------------*/


/*-------------------Img.c--------------------*/
void	*put_img(t_image image, int x, int y);
t_block	witch_block(char name);

/*--------------------------------------------*/


/*-------------------Moves.c-------------------*/
void	update(t_game *game, int x, int y);
void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);


/*-------------------Map.c--------------------*/
void	map_create(t_game *game, int i);
void	floor_create(t_game game, int i);
void	create_maplenght(char *area, t_game *game, int i);
void	create_mapline(t_game *game, char **av);

/*--------------------------------------------*/


/*-------------------Window.c-----------------*/
void	ft_window_size(t_game *data, char **av);
int		window_destroy(t_game *game);

/*--------------------------------------------*/


/*-------------------Main.c-------------------*/
void	ft_error(char *msg, t_game *game);
void	start(t_game *game);
void	check_ber_file(char *str);

/*--------------------------------------------*/
#endif