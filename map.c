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

void	flor_create(t_game, int i)
{
	int		j;
	t_image	image;

	image.wlx = game;
	j = 0;
	if (ft_strlen(game.map[i]) != game.size_x / 48 && b != (game.size_y / 48))
		ft_error
}

void	create_maplenght(char *area, t_game *game, int i)
{
	int		j;
	t_image	image;

	j = 0;
	image.wlx = *game; 
	game->map[i] = (char *)malloc(sizeof(char) * (10000));
	while (area[j] != '\0')
	{
		if (area[j] == '\n')
			break ;
		game->map[i][j] = area[j];
		j++;
	}
	floor_create(*game, i);
	map_create(game, i);
}

void	create_mapline(t_game *game, char **argv)
{
	int		fd;
	char	*area;
	int		i;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (10000));
	fd_open(argv[1], O_RDONLY);
	while (i <= game->size_y / 48)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_maplenght(area, game, i);
		i++;
	}
	
}