/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:58:41 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/12 17:19:55 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ml/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
 
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	int x;
	int y;
} t_data;
 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	int width;
	int height;

	printf("Pressed key: %d\n", keysym);
	if	(keysym == 65307)
		on_destroy(data);
	if (keysym == 100)
	{
		void *map;
		void *perso;
		map = mlx_xpm_file_to_image(data->mlx_ptr, "asset/map.xpm", &width, &height);
		perso = mlx_xpm_file_to_image(data->mlx_ptr, "asset/homer_carre.xpm", &width, &height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map, 0, 0);
		data->x = data->x + 100;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, perso, data->x , data->y);
	}
	return (0);
}
 
int main(void)
{
	t_data data;
	void	*img;
	void	*perso;
	int		width;
	int		height;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1280, 720, "hi");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);	
	 
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_mouse_hook(data.win_ptr, &on_keypress, &data);	
 
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	
	img = mlx_xpm_file_to_image(data.mlx_ptr, "asset/homer_carre.xpm", &width, &height);
	perso = mlx_xpm_file_to_image(data.mlx_ptr, "asset/map.xpm", &width, &height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, perso, 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 250, 250);
	data.x = 250;
	data.y = 250;
	
	mlx_loop(data.mlx_ptr);
	return (0);
}