/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:57:24 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/14 18:21:58 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_map(t_data *data)
{
	int	x;
	int	y;
	void	*mapi;
	void	*mur;
	int		width;
	int		height;

	mapi = mlx_xpm_file_to_image(data->mlx_ptr, "asset/Gras.xpm", &width, &height);
	mur = mlx_xpm_file_to_image(data->mlx_ptr, "asset/homer_49.xpm", &width, &height);
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, mur , x * 49, y * 49);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->coins.img , x * 49, y * 49);
			else if (data->map[y][x] == 'P' && data->player.y == 0)
				set_pos(data, x, y);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, mapi, x * 49, y * 49);
		}
	}
}

void	print_xpm(t_data *data)
{
	print_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img, data->player.x * 49, data->player.y * 49);
}
