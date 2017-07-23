/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <mpotapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:53:09 by mpotapov          #+#    #+#             */
/*   Updated: 2017/03/25 19:28:32 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		tobigarr(char **arr)
{
	char	*temp;

	temp = NULL;
	if (!(temp = ft_strnew(ft_strlen(*arr))))
		return (0);
	ft_strcpy(temp, *arr);
	ft_strdel(arr);
	if (!(*arr = ft_strnew(ft_strlen(temp) + BUFF_SIZE)))
		return (0);
	ft_strcpy(*arr, temp);
	ft_strdel(&temp);
	return (1);
}

int		copyinline(char **arr, char **line)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while ((*arr)[x] != '\n')
	{
		(*line)[x] = (*arr)[x];
		x++;
	}
	(*line)[x] = '\0';
	x++;
	while ((*arr)[x])
	{
		(*arr)[i] = (*arr)[x];
		(*arr)[x] = '\0';
		x++;
		i++;
	}
	(*arr)[i] = '\0';
	while ((*arr)[i])
		(*arr)[i++] = '\0';
	return (1);
}

int		read_alg(int fd, char **arr)
{
	char	*mass;
	int		i;

	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, *arr, 0) == -1
		|| BUFF_SIZE > 3000000)
		return (-1);
	if (!*arr)
		*arr = ft_strnew(BUFF_SIZE);
	mass = NULL;
	if (!(mass = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((i = read(fd, mass, BUFF_SIZE)) > 0)
	{
		if (!(tobigarr(arr)))
			return (-1);
		ft_strncat(*arr, mass, BUFF_SIZE);
		if (ft_memchr(mass, '\n', BUFF_SIZE))
		{
			ft_strdel(&mass);
			break ;
		}
		ft_bzero(mass, BUFF_SIZE);
	}
	ft_strdel(&mass);
	return (i);
}

void	without_lf(char *arr1)
{
	int x;

	x = 0;
	while (arr1[x])
		x++;
	if (arr1[x - 1] != '\n')
	{
		arr1[x] = '\n';
		arr1[x + 1] = '\0';
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*arr;
	int			x;
	int			i;

	x = 0;
	i = read_alg(fd, &arr);
	if (i == -1)
		return (-1);
	if ((ft_strcmp(arr, "\0") == 0))
	{
		ft_strdel(&arr);
		return (i);
	}
	if (i == 0)
		without_lf(arr);
	if (ft_memchr(arr, '\n', ft_strlen(arr)) && (ft_strcmp(arr, "\0") == 0))
	{
		ft_strdel(&arr);
		return (0);
	}
	if (!(*line = ft_strnew(ft_strlen(arr))) || !line)
		return (-1);
	copyinline(&arr, line);
	return (1);
}
