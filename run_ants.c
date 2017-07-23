/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 14:23:23 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/14 14:23:40 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*c_node(int ind, t_str *strct)
{
	t_node *q;

	q = (struct s_node *)malloc(sizeof(struct s_node));
	q->data = ind;
	q->ind_to_go = -1;
	q->prev_ind = -1;
	q->name = ft_strdup(strct->rooms[ind]);
	q->next = NULL;
	return (q);
}

void	print_ways(t_str *strct)
{
	int		i;
	t_node	*trav;

	i = 0;
	write(1, "Ways:\n", 6);
	while (i < strct->num_way && i < strct->num_print_ways)
	{
		trav = strct->array[i].head;
		while (trav != NULL)
		{
			write(1, "[", 1);
			write(1, trav->name, ft_strlen(trav->name));
			write(1, "]", 1);
			trav = trav->next;
			if (trav)
				write(1, "->", 2);
		}
		i++;
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void	add_edge(t_str *strct, int i, int data)
{
	t_node *tmp;

	tmp = c_node(data, strct);
	tmp->next = strct->array[i].head;
	strct->array[i].head = tmp;
}

void	run_ants(t_str *strct)
{
	int i;
	int j;

	strct->array =
			(struct s_lst *)malloc(sizeof(struct s_lst) * strct->num_way);
	i = 0;
	if (strct->num_way == 0)
		ft_exit(strct);
	while (i < strct->num_way)
		strct->array[i++].head = NULL;
	i = 0;
	while (i < strct->num_way)
	{
		j = 0;
		while (strct->ways[i][j] != -1)
		{
			add_edge(strct, i, strct->ways[i][j]);
			j++;
		}
		strct->array[i].number_ways = j;
		i++;
	}
	if (strct->print_ways != -1)
		print_ways(strct);
	print_ants(strct);
}
