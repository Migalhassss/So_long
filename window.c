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

void	ft_window_size(t_game *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\n", data);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_error("Error\n", data);
	data->size_x = (ft_line(fd) * 48);
	data->size_y = ft_count_lin(fd) * 48;
}