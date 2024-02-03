/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:55:08 by aschmitt          #+#    #+#             */
/*   Updated: 2024/02/03 00:44:13 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_recursive_putnbr(int nb)
{
	if (nb / 10 == 0)
		ft_putchar_fd('0' + nb % 10, 1);
	else
	{
		ft_recursive_putnbr(nb / 10);
		ft_putchar_fd('0' + nb % 10, 1);
	}
}

void	ft_put_count(int n)
{
	ft_putstr_fd("count: ", 1);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	ft_recursive_putnbr(n);
	ft_putchar_fd('\n', 1);
}

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	set_pos(t_data *data, int x, int y)
{
	if (x >= data->width)
		x = data->width - 1;
	else if (x < 0)
		x = 0;
	if (y >= data->height)
		y = data->height - 1;
	else if (y < 0)
		y = 0;
	if (data->map[y][x] == '1')
	{
		x = data->player.x;
		y = data->player.y;
	}
	if (data->player.x != x || data->player.y != y)
	{
		if (data->map[y][x] == 'C')
			data->map[y][x] = '0';
		put_mouv(data, x, y);
		data->player.x = x;
		data->player.y = y;
		data->n++;
		ft_put_count(data->n);
	}
}
