/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 17:12:31 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/19 20:55:11 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_go	*add_to_go(int ant, int room, t_go *go)
{
	t_go *g;

	g = (struct s_go *)malloc(sizeof(struct s_go));
	g->next = NULL;
	g->ant_ind = ant;
	g->room_ind = room;
	g->next = go;
	go = g;
	return (go);
}

t_go	*from_start(t_str *strct, t_go *go)
{
	int		i;
	t_node	*t;

	if (strct->ant != strct->num_ants + 1)
	{
		i = 0;
		while (i < strct->num_way)
		{
			if (i == 0 || (strct->num_ants - strct->ant >=
					strct->array[i].number_ways - strct->array[0].number_ways))
			{
				t = strct->array[i].head;
				go = add_to_go(strct->ant, t->next->data, go);
				t->next->ind_to_go = strct->ant;
				if (t->next->data == strct->ind_end)
					strct->ants_in_end++;
				strct->ant++;
			}
			i++;
		}
	}
	return (go);
}

t_go	*sort_list(t_go *go)
{
	t_go	*tmp;
	int		tmp1;

	tmp = go;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->ant_ind > tmp->next->ant_ind)
		{
			tmp1 = tmp->ant_ind;
			tmp->ant_ind = tmp->next->ant_ind;
			tmp->next->ant_ind = tmp1;
			tmp1 = tmp->room_ind;
			tmp->room_ind = tmp->next->room_ind;
			tmp->next->room_ind = tmp1;
			tmp = go;
		}
		else
			tmp = tmp->next;
	}
	return (go);
}

void	print_step(t_go *go, t_str *strct)
{
	t_go	*g;
	char	*s;

	go = sort_list(go);
	g = go;
	while (g != NULL)
	{
		s = ft_itoa(g->ant_ind);
		write(1, "L", 1);
		write(1, s, ft_strlen(s));
		ft_strdel(&s);
		write(1, "-", 1);
		write(1, strct->rooms[g->room_ind],
			ft_strlen(strct->rooms[g->room_ind]));
		write(1, " ", 1);
		g = g->next;
	}
	if (strct->array[0].head->next->data != strct->ind_end)
		write(1, "\n", 1);
}

void	print_ants(t_str *strct)
{
	t_go *go;
	t_go *tmp;

	go = NULL;
	strct->ant = 1;
	strct->ants_in_end = 0;
	while (strct->ants_in_end != strct->num_ants)
	{
		if (strct->array[0].head->next->data != strct->ind_end)
			go = go_for_one_step(strct, go);
		go = from_start(strct, go);
		print_step(go, strct);
		while (go != NULL)
		{
			tmp = go->next;
			free(go);
			go = tmp;
		}
	}
	if (strct->array[0].head->next->data == strct->ind_end)
		write(1, "\n", 1);
}
