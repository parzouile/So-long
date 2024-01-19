/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:47:44 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/19 09:38:11 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->player.img);
	mlx_destroy_image(data->mlx_ptr, data->coins);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->walls);
	mlx_destroy_image(data->mlx_ptr, data->grass);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
int on_destroy(t_data *data)
{
	int	i;

	i = -1;
	if (data->map)
	{
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	free_mlx(data);
	exit(0);
	return (0);
}

void	ft_error(char *str, t_data *data)
{
	int	i;

	printf("%s", str);
	i = -1;
	if (data->map)
	{
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	free_mlx(data);
	exit(1);
}

void	init_xpm(t_data *data)
{
	int	width;
	int height;

	data->player.size = 49;
	data->player.img = mlx_xpm_file_to_image(data->mlx_ptr, "asset/Homer.xpm", &width, &height);
	data->coins = mlx_xpm_file_to_image(data->mlx_ptr, "asset/donut.xpm", &width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "asset/exit.xpm", &width, &height);
	data->walls = mlx_xpm_file_to_image(data->mlx_ptr, "asset/homer_49.xpm", &width, &height);
	data->grass = mlx_xpm_file_to_image(data->mlx_ptr, "asset/Gras.xpm", &width, &height);
	data->player.x = 0;
	data->player.y = 0;
	data->n = 0;
	data->win_ptr = NULL;
	data->map = NULL;
}

int on_keypress(int keysym, t_data *data)
{
	if	(keysym == 65307)
		on_destroy(data);
	if (keysym == 100)
		set_pos(data, data->player.x + 1, data->player.y);
	if (keysym == 97)
		set_pos(data, data->player.x - 1, data->player.y);
	if (keysym == 115)
		set_pos(data, data->player.x, data->player.y + 1);
	if (keysym == 119)
		set_pos(data, data->player.x, data->player.y - 1);
	if (data->map[data->player.y][data->player.x] == 'E' && is_finish(data))
		on_destroy(data);
	else
		print_xpm(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	init_xpm(&data);
	init_map(&data, argv);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.width * data.player.size, data.height * data.player.size, "hi");
	if (!data.win_ptr)
		ft_error("Error\nWindow error", &data);
	print_xpm(&data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
