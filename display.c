/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:57:24 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/14 23:22:01 by aschmitt         ###   ########.fr       */
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
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->walls , x * 49, y * 49);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->coins , x * 49, y * 49);
			else if (data->map[y][x] == 'P' && data->player.y == 0)
				set_pos(data, x, y);
			else if (data->map[y][x] == 'E' && is_finish(data) == 1)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit , x * 49, y * 49);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->grass, x * 49, y * 49);
		}
	}
}

void	print_xpm(t_data *data)
{
	print_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img, data->player.x * 49, data->player.y * 49);
}
