/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:47:44 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/14 18:47:55 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_error(char *str, t_data *data)
{
	int	i;

	i = -1;
	printf("%s", str);
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	free(data->mlx_ptr);
	exit(0);
}

void	aux(t_data *data)
{
	int	i;
	int j;
	
	j = -1;
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			printf("%c", data->map[i][j]);
	}
	printf("\n%d\n", data->width);
	printf("%d\n", data->height	);
}

int on_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	init_xpm(t_data *data)
{
	int	width;
	int height;

	data->player.size = 49;
	data->player.img = mlx_xpm_file_to_image(data->mlx_ptr, "asset/Homer.xpm", &width, &height);
	data->coins.img = mlx_xpm_file_to_image(data->mlx_ptr, "asset/donut.xpm", &width, &height);
	data->coins.x = 5;
	data->coins.y = 2;
	data->player.x = 0;
	data->player.y = 0;
	data->n = 0;
}

int on_keypress(int keysym, t_data *data)
{
	if	(keysym == 65307)
		on_destroy(data);
	if (keysym == 100)
		set_pos(data, data->player.x + 1, data->player.y);
	if (keysym == 113)
		set_pos(data, data->player.x - 1, data->player.y);
	if (keysym == 115)
		set_pos(data, data->player.x, data->player.y + 1);
	if (keysym == 122)
		set_pos(data, data->player.x, data->player.y - 1);
	if (check_pos(data))
		print_xpm(data);
	else
		on_destroy(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	init_map(&data, argv);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.width * 49, data.height * 49, "hi");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	init_xpm(&data)
	print_xpm(&data);
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	
	
	mlx_loop(data.mlx_ptr);
	return (0);
}
