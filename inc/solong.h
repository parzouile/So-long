/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:18:05 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/25 10:27:32 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <ml/mlx.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# define S 49

typedef struct s_player
{
	int		x;
	int		y;
	void	*img;
}				t_player;

typedef struct s_Point
{
	int	row;
	int	col;
}				t_Point;

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

char	*get_next_line(int fd, t_data *data);
int		ft_strlen(const char *s);
int		check_nl(char *stack);
char	*add_to_stack(char *stack, char *buff);
char	*ft_strdup(char *buff);
void	ft_error(char *s, t_data *data);
void	print_xpm(t_data *data);
int		check_pos(t_data *data);
void	set_pos(t_data *data, int x, int y);
void	init_map(t_data *data, char **argv);
void	aux(t_data *data);
int		is_finish(t_data *data);
void	check_solution(t_data *data);
int		size_line(char *s);
t_Point	new_point(int i, int j);
int		move_valid(t_data *data, char **map, int row, int col);
void	*to_img(t_data *data, char *s);
void	*n_w(t_data *d);
void	free_mlx(t_data *data);

#endif