/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:18:05 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/12 02:44:54 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_player {
	int     x;
	int     y;
}				t_player;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data		img;
	t_player    player;
}				t_vars;



# include <unistd.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>

int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);

#endif