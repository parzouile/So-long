/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:57:24 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/22 15:57:48 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

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

void	put(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * 49, y * 49);
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
				put(data, data->walls, x, y);
			else if (data->map[y][x] == 'C')
				put(data, data->coins, x, y);
			else if (data->map[y][x] == 'P' && data->player.y == 0)
				set_pos(data, x, y);
			else if (data->map[y][x] == 'E' && is_finish(data) == 1)
				put(data, data->exit, x, y);
			else if (data->map[y][x] == '0' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'P' )
				put(data, data->grass, x, y);
			else
				ft_error("Error\nMap error\n", data);
		}
	}
}

void	print_xpm(t_data *data)
{
	print_map(data);
	put(data, data->player.img, data->player.x, data->player.y);
}
