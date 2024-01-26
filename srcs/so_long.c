/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:47:44 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/26 16:17:06 by aschmitt         ###   ########.fr       */
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

int	on_destroy(t_data *data)
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

void	init_xpm(t_data *data)
{
	data->player.img = to_img(data, "asset/G2/player.xpm");
	data->coins = to_img(data, "asset/G2/coin.xpm");
	data->exit = to_img(data, "asset/G2/door.xpm");
	data->walls = to_img(data, "asset/G2/tree.xpm");
	data->grass = to_img(data, "asset/G2/grass.xpm");
	data->player.x = 0;
	data->player.y = 0;
	data->n = 0;
	data->win_ptr = NULL;
	data->map = NULL;
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
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
	data.win_ptr = n_w(&data);
	if (!data.win_ptr)
		ft_error("Error\nWindow error", &data);
	print_xpm(&data);
	mlx_hook(data.win_ptr, 3, 1L << 1, &on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
