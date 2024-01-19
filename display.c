/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:57:24 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/19 10:06:00 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	is_finish(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == 'C')
				return (0);
	}
	return (1);
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->walls , x * data->player.size, y * data->player.size);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->coins , x * data->player.size, y * data->player.size);
			else if (data->map[y][x] == 'P' && data->player.y == 0)
				set_pos(data, x, y);
			else if (data->map[y][x] == 'E' && is_finish(data) == 1)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit , x * data->player.size, y * data->player.size);
			else if (data->map[y][x] == '0' || data->map[y][x] == 'E' || data->map[y][x] == 'P' )
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->grass, x * data->player.size, y * data->player.size);
			else
				ft_error("Error\nMap error\n", data);
		}
	}
}

void	print_xpm(t_data *data)
{
	print_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img, data->player.x * data->player.size, data->player.y * data->player.size);
}
