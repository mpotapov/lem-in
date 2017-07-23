/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_for_one_step.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:52:39 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/19 20:52:55 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	write_line(char *line, t_str *strct)
{
	strct->line_print = ft_strjoin(strct->line_print, line);
	strct->line_print = ft_strjoin(strct->line_print, "\n");
}

void	ft_exit(t_str *strct)
{
	if (strct->is_links == 1 && strct->end_read == 0)
	{
		write(1, strct->line_print, ft_strlen(strct->line_print));
		ft_putstr("ERROR\n");
		write(1, "\n", 1);
		alg(strct);
		strct->is_links = 0;
	}
	else
		ft_putstr("ERROR\n");
	exit(1);
}

t_go	*go_for_one_step1(t_str *strct, t_go *go, t_node *t)
{
	if (t->data != strct->ind_st)
	{
		t->next->prev_ind = t->ind_to_go;
		if (t->ind_to_go != -1)
			go = add_to_go(t->ind_to_go, t->next->data, go);
		t->ind_to_go = t->prev_ind;
	}
	return (go);
}

t_go	*go_for_one_step(t_str *strct, t_go *go)
{
	int		i;
	t_node	*t;

	i = 0;
	while (i < strct->num_way)
	{
		t = strct->array[i].head;
		while (t != NULL)
		{
			if (t->data == strct->ind_end)
			{
				if (t->prev_ind != -1 || t->ind_to_go != -1)
					strct->ants_in_end++;
				break ;
			}
			go = go_for_one_step1(strct, go, t);
			t = t->next;
		}
		i++;
	}
	return (go);
}
