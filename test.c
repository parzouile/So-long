/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:58:41 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/14 17:00:57 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>
#include <stdlib.h>

 
/*
 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
void	print_map(t_data *data)
{
	int	x;
	int	y;
	void	*map;
	int		width;
	int		height;

	map = mlx_xpm_file_to_image(data->mlx_ptr, "asset/Gras.xpm", &width, &height);
	x = -1;
	while (++x < 13)
	{
		printf("x = %d\n", x);
		y = -1;
		while (++y < 5)
		{
			printf("y = %d\n", y);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map, x * 49, y * 49);
		}
	}
}

void	print_xpm(t_data *data)
{
	print_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->coins.img, data->coins.x, data->coins.y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img, data->player.x, data->player.y);
	
}

void	set_pos(t_data *data, int x, int y)
{
	if (x + data->player.size > data->width)
		x = data->width - data->player.size;
	else if (x < 0)
		x = 0;
	if (y + data->player.size > data->height)
		y = data->height - data->player.size;
	else if (y < 0)
		y = 0;
	if (data->player.x != x || data->player.y != y)
	{
		data->player.x = x;
		data->player.y = y;
		data->n++;
		printf("count: %d\n", data->n);
	}
}

int	check_pos(t_data *data)
{
	(void)data;
	return(1);
}
 
int on_keypress(int keysym, t_data *data)
{
	
	if	(keysym == 65307)
		on_destroy(data);
	if (keysym == 100)
		set_pos(data, data->player.x + data->player.size, data->player.y);
	if (keysym == 113)
		set_pos(data, data->player.x - data->player.size, data->player.y);
	if (keysym == 115)
		set_pos(data, data->player.x, data->player.y + data->player.size);
	if (keysym == 122)
		set_pos(data, data->player.x, data->player.y - data->player.size);
	if (check_pos(data))
		print_xpm(data);
	else
		on_destroy(data);
	return (0);
}


 
int main(void)
{
	t_data data;
	int		width;
	int		height;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 13 * 49, 5 * 49, "hi");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	
	data.height = 5 * 49;
	data.width = 13 * 49;
	data.n = 0;
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	data.map = mlx_xpm_file_to_image(data.mlx_ptr, "asset/map.xpm", &width, &height);
	data.player.x = 0;
	data.player.y = 0;
	data.player.size = 49;
	data.player.img = mlx_xpm_file_to_image(data.mlx_ptr, "asset/homer_49.xpm", &width, &height);
	data.coins.img = mlx_xpm_file_to_image(data.mlx_ptr, "asset/donut.xpm", &width, &height);
	data.coins.x = 5 * 49;
	data.coins.y = 2 * 49;
	print_xpm(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}*/