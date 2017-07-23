/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_and_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:51:41 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/22 13:34:44 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	to_big_first_room(t_str *strct)
{
	strct->rooms = (char**)malloc(sizeof(char*) * 2);
	strct->rooms[0] = ft_strdup(strct->room_name);
	strct->rooms[1] = 0;
}

void	make_adj_matrix(t_str *strct)
{
	int i;
	int j;

	strct->is_matrix = 1;
	strct->matrix = (int**)malloc(sizeof(int*) * strct->count_rooms + 1);
	i = 0;
	while (i < strct->count_rooms)
	{
		j = 0;
		strct->matrix[i] = (int*)malloc(sizeof(int) * strct->count_rooms);
		while (j < strct->count_rooms)
			strct->matrix[i][j++] = 0;
		i++;
	}
}

void	to_matrix(t_str *strct)
{
	int i;
	int j;
	int n;

	n = 0;
	i = 0;
	j = 0;
	while (n < strct->count_rooms)
		if (ft_strcmp(strct->name_link1, strct->rooms[n++]) == 0)
		{
			i = --n;
			break ;
		}
	n = 0;
	while (n < strct->count_rooms)
		if (ft_strcmp(strct->name_link2, strct->rooms[n++]) == 0)
		{
			j = --n;
			break ;
		}
	strct->matrix[i][j] = 1;
	strct->matrix[j][i] = 1;
}

int		check_link2(t_str *strct, char *line, int i)
{
	strct->name_link1 = ft_strdup(strct->rooms[i]);
	while (*line != '-')
		line++;
	line++;
	i = 0;
	while (i < strct->count_rooms)
	{
		if (ft_strcmp(strct->rooms[i], line) == 0)
		{
			strct->name_link2 = ft_strdup(strct->rooms[i]);
			to_matrix(strct);
			ft_strdel(&strct->name_link1);
			ft_strdel(&strct->name_link2);
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_link(char *line, t_str *strct)
{
	int i;
	int j;

	if (strct->count_rooms == 0 || !ft_strchr(line, '-'))
		ft_exit(strct);
	if (strct->is_matrix == 0)
		make_adj_matrix(strct);
	j = 0;
	while (line[j] != '-')
		j++;
	i = 0;
	while (i < strct->count_rooms)
	{
		if (ft_strncmp(strct->rooms[i], line,
		(ft_strlen(strct->rooms[i]) > (size_t)j) ? ft_strlen(line) : j) == 0)
		{
			if (check_link2(strct, line, i) == 0)
				break ;
			return ;
		}
		i++;
	}
	ft_exit(strct);
}
