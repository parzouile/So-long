/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:17:08 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/12 03:24:57 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	echap(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	print_map_player(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
			{
				my_mlx_pixel_put(&(vars->img), i, j,  create_trgb(0,255,0,0));
				j++;
			}
		i++;
	}
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
			{
				my_mlx_pixel_put(&(vars->img), vars->player.x + i,  vars->player.y + j,  create_trgb(0,0,0,255));
				j++;
			}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	new_player(t_vars *vars, int x, int y)
{
	vars->player.x = x;
	vars->player.y = y;
}

int	key_hook(int keycode, t_vars *vars)
{
	
	printf("keycode = %d\n", keycode);
	if (keycode == 65307 )
		echap(vars);
	if (keycode == 65363 )
	{
		new_player(vars,  vars->player.x + 20,  vars->player.y);
		print_map_player(vars);
	}
	if (keycode == 65361 )
	{
		new_player(vars,  vars->player.x - 20,  vars->player.y);
		print_map_player(vars);
	}
	if (keycode == 65364 )
	{
		new_player(vars,  vars->player.x ,  vars->player.y + 20);
		print_map_player(vars);
	}
	if (keycode == 65362 )
	{
		new_player(vars,  vars->player.x,  vars->player.y - 20);
		print_map_player(vars);
	}
	return (0);
}





int	main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &(vars.img.bits_per_pixel), &(vars.img.line_length), &(vars.img.endian));
	new_player(&vars, 0, 0);
	
	print_map_player(&vars);
	
	///mlx_loop_hook(vars.mlx, print_map_player, &vars);
	
	
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, key_hook, &vars);
	
	mlx_loop(vars.mlx);
}
