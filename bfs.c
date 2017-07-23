/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 19:26:31 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/19 19:26:44 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	if_one_vertex(t_str *strct, int i)
{
	int j;

	j = 0;
	while (strct->matrix[i][j] != 1)
		j++;
	strct->matrix[i][j] = 0;
	strct->matrix[j][i] = 0;
}

void	norme_mtx(t_str *strct)
{
	int n;
	int i;
	int j;

	i = 0;
	while (i < strct->count_rooms)
	{
		j = 0;
		n = 0;
		if (strct->matrix[i][i] == 1)
			strct->matrix[i][i] = 0;
		while (j < strct->count_rooms)
		{
			if (strct->matrix[i][j] == 1)
				n++;
			j++;
		}
		if (n == 1 && ft_strcmp(strct->rooms[i], strct->room_name_start) != 0
			&& ft_strcmp(strct->rooms[i], strct->room_name_end) != 0)
			if_one_vertex(strct, i);
		i++;
	}
}

int		burn(t_str *strct, int ind)
{
	int i;

	i = 0;
	while (strct->queue[i] != -1)
		if (strct->queue[i++] == ind)
			return (1);
	i = 0;
	while (strct->stack[i] != -1)
		if (strct->stack[i++] == ind)
			return (1);
	return (0);
}

void	if_burn(t_str *strct, int i)
{
	strct->matrix[strct->stack[strct->s]][i] = 0;
	strct->matrix[i][strct->stack[strct->s]] = 0;
	strct->stack[++strct->s1] = i;
	strct->path[strct->s1] = strct->stack[strct->s];
}

int		bfs(t_str *strct)
{
	int i;

	strct->stack[0] = strct->ind_st;
	strct->q = 0;
	strct->s = 0;
	strct->s1 = 0;
	while (1)
	{
		if (strct->stack[strct->s] == -1)
			return (1);
		strct->queue[strct->q] = strct->stack[strct->s];
		if (strct->queue[strct->q] == strct->ind_end)
			break ;
		i = 0;
		while (i < strct->count_rooms)
		{
			if (strct->matrix[strct->stack[strct->s]][i]
				== 1 && burn(strct, i) != 1)
				if_burn(strct, i);
			i++;
		}
		strct->stack[strct->s++] = -2;
		strct->q++;
	}
	return (0);
}
