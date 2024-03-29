/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:40:47 by aschmitt          #+#    #+#             */
/*   Updated: 2024/02/03 02:06:04 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*find_line(char *stack, char *buff, int fd)
{
	int	res;

	res = read(fd, buff, BUFFER_SIZE);
	while (res > 0)
	{
		buff[res] = 0;
		if (!stack && buff)
			stack = ft_strdup(buff);
		else
			stack = add_to_stack(stack, buff);
		if (!stack || check_nl(stack) != -1)
			res = 0;
		else
			res = read(fd, buff, BUFFER_SIZE);
	}
	if (res < 0)
	{
		if (stack)
			free(stack);
		free(buff);
		return (NULL);
	}
	free(buff);
	return (stack);
}

char	*ft_line(char *stack)
{
	int		size;
	int		i;
	char	*line;

	size = check_nl(stack);
	if (size == -1)
		size = ft_strlen(stack);
	else
		size ++;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (free(stack), NULL);
	i = -1;
	while (++i < size)
		line[i] = stack[i];
	line[i] = 0;
	return (line);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_restack(char *stack)
{
	int		i;
	int		size;
	char	*new_stack;

	i = check_nl(stack);
	size = 0;
	new_stack = NULL;
	if (i == -1)
	{
		free(stack);
		return (new_stack);
	}
	if (stack[i] && stack[i + 1])
		while (stack[i + size])
			size ++;
	if (size > 0)
	{
		new_stack = malloc(sizeof(char) * (size));
		if (new_stack)
			ft_strcpy(new_stack, stack + i + 1);
	}
	free(stack);
	return (new_stack);
}

char	*get_next_line(int fd, t_data *data)
{
	static char	*stack;
	char		*buff;
	char		*line;

	(void)data;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	stack = find_line(stack, buff, fd);
	if (!stack)
		return (NULL);
	line = ft_line(stack);
	stack = ft_restack(stack);
	return (line);
}
