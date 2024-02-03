/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:57:24 by aschmitt          #+#    #+#             */
/*   Updated: 2024/02/03 00:47:11 by aschmitt         ###   ########.fr       */
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

void	put(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * S, y * S);
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
			else if (data->map[y][x] == '0' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'P' )
				put(data, data->grass, x, y);
			else
				ft_error("Error\nMap error\n", data);
		}
	}
	put(data, data->player.img, data->player.x, data->player.y);
}

void	put_mouv(t_data *data, int x, int y)
{
	put(data, data->grass, data->player.x, data->player.y);
	put(data, data->player.img, x, y);
	if (is_finish(data) == 1)
	{
		y = 0;
		while (++y < data->height)
		{
			x = 0;
			while (++x < data->width)
				if (data->map[y][x] == 'E')
					put(data, data->exit, x, y);
		}
	}
}
