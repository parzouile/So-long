/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:18:05 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/19 10:17:44 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H


typedef struct	s_player {
	int     x;
	int     y;
	int		size;
	void	*img;
}				t_player;

typedef struct	s_coins {
	int     x;
	int     y;
	int		alive;
	void	*img;
}				t_coins;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*exit;
	void		*coins;
	void		*walls;
	void		*grass;
	int			width;
	int			height;
	int			n;
	char		**map;
	t_player	player;
}				t_data;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data		img;
	t_player    player;
	int		width;
	int		height;
}				t_vars;



# include <unistd.h>
# include <stdio.h>
# include "ml/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd, t_data *data);
int	ft_strlen(const char *s);
int		check_nl(char *stack);
char	*add_to_stack(char *stack, char *buff);
char	*ft_strdup(char *buff);

int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
void	ft_error(char *s, t_data *data);
void	print_xpm(t_data *data);
int		check_pos(t_data *data);
void	set_pos(t_data *data, int x, int y);
void	init_map(t_data *data, char **argv);
void	aux(t_data *data);
int		is_finish(t_data *data);

#endif