/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 20:05:01 by mpotapov          #+#    #+#             */
/*   Updated: 2017/06/29 20:05:27 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	make_dublicat_mtx(t_str *strct)
{
	int i;
	int j;

	strct->matrix1 = (int **)malloc(sizeof(int *) * strct->count_rooms);
	i = 0;
	while (i < strct->count_rooms)
		strct->matrix1[i++] = (int *)malloc(sizeof(int) * strct->count_rooms);
	i = 0;
	while (i < strct->count_rooms)
	{
		j = 0;
		while (j < strct->count_rooms)
		{
			strct->matrix1[i][j] = strct->matrix[i][j];
			j++;
		}
		i++;
	}
}

void	kill_links(t_str *strct)
{
	int i;
	int j;

	i = 1;
	while (strct->ways[strct->num_way][i + 1] != -1)
	{
		j = 0;
		while (j < strct->count_rooms)
		{
			if (strct->matrix1[strct->ways[strct->num_way][i]][j] == 1)
			{
				strct->matrix1[strct->ways[strct->num_way][i]][j] = 0;
				strct->matrix1[j][strct->ways[strct->num_way][i]] = 0;
			}
			j++;
		}
		i++;
	}
}

void	malloc_mem(t_str *strct)
{
	int i;
	int j;

	j = 0;
	strct->queue = (int *)malloc(sizeof(int) * strct->count_rooms + 1);
	strct->stack = (int *)malloc(sizeof(int) * strct->count_rooms + 1);
	strct->path = (int *)malloc(sizeof(int) * strct->count_rooms + 1);
	i = 0;
	strct->ways = (int **)malloc(sizeof(int *) * strct->count_rooms);
	while (i < strct->num_of_ways)
	{
		strct->ways[i] = (int *)malloc(sizeof(int) * strct->count_rooms + 1);
		while (j < strct->count_rooms + 1)
			strct->ways[i][j++] = -1;
		i++;
	}
}

void	matrix1_into_matrix(t_str *strct)
{
	int i;
	int j;

	i = 0;
	while (i < strct->count_rooms)
	{
		j = 0;
		while (j < strct->count_rooms)
		{
			if (strct->matrix[i][j] == 1)
				strct->matrix[i][j] = 0;
			strct->matrix[i][j] = strct->matrix1[i][j];
			j++;
		}
		i++;
	}
}

void	alg(t_str *strct)
{
	strct->is_links == 0 ? ft_exit(strct) : 0;
	strct->end_read = 1;
	find_num_of_ways(strct);
	norme_mtx(strct);
	malloc_mem(strct);
	make_dublicat_mtx(strct);
	strct->num_way = 0;
	while (strct->num_way != strct->num_of_ways)
	{
		make_mass_to_bfs(strct);
		if (bfs(strct) == 1)
			break ;
		find_way(strct);
		kill_links(strct);
		matrix1_into_matrix(strct);
		strct->num_way++;
	}
	run_ants(strct);
}
