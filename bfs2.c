/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 19:31:48 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/19 19:32:11 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	make_mass_to_bfs(t_str *strct)
{
	int i;

	i = 0;
	while (i < strct->count_rooms + 1)
	{
		strct->queue[i] = -1;
		strct->path[i] = -1;
		strct->stack[i] = -1;
		i++;
	}
	strct->path[0] = -2;
}

void	find_ind_st_end(t_str *strct)
{
	int	i;

	i = 0;
	strct->room_name_start == NULL ? ft_exit(strct) : 0;
	strct->room_name_end == NULL ? ft_exit(strct) : 0;
	while (i < strct->count_rooms)
	{
		if (ft_strcmp(strct->rooms[i], strct->room_name_start) == 0)
			strct->ind_st = i;
		if (ft_strcmp(strct->rooms[i], strct->room_name_end) == 0)
			strct->ind_end = i;
		i++;
	}
}

void	find_num_of_ways(t_str *strct)
{
	int i;
	int j;

	find_ind_st_end(strct);
	i = 0;
	strct->num_of_ways = 0;
	while (i < strct->count_rooms)
		if (strct->matrix[strct->ind_st][i++] == 1)
			strct->num_of_ways++;
	i = 0;
	j = 0;
	while (i < strct->count_rooms)
		if (strct->matrix[strct->ind_end][i++] == 1)
			j++;
	if (j < strct->num_of_ways)
		strct->num_of_ways = j;
}

void	find_way(t_str *strct)
{
	int i;
	int ind;
	int p1;

	p1 = 0;
	ind = strct->ind_end;
	while (1)
	{
		i = 0;
		while (strct->queue[i] != ind)
			i++;
		strct->ways[strct->num_way][p1++] = strct->queue[i];
		ind = strct->path[i];
		if (ind == strct->ind_st)
		{
			strct->ways[strct->num_way][p1++] = strct->ind_st;
			strct->ways[strct->num_way][p1] = -1;
			break ;
		}
	}
}
