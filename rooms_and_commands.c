/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_and_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:52:46 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/19 18:52:58 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	to_big(t_str *strct)
{
	char	**tmp;
	int		i;

	i = 0;
	if (strct->count_rooms == 1)
		to_big_first_room(strct);
	else
	{
		tmp = (char**)malloc(sizeof(char*) * strct->count_rooms + 1);
		while (i < strct->count_rooms - 1)
		{
			tmp[i] = ft_strdup(strct->rooms[i]);
			i++;
		}
		tmp[i++] = ft_strdup(strct->room_name);
		tmp[i] = 0;
		i = 0;
		while (i < strct->count_rooms - 1)
			ft_strdel(&strct->rooms[i++]);
		free(strct->rooms);
		strct->rooms = tmp;
	}
}

char	*printways(t_str *strct, int fd, char *s)
{
	write_line(s, strct);
	ft_strdel(&s);
	get_next_line(fd, &s) == 0 ? ft_exit(strct) : 0;
	strct->num_print_ways = ft_atoi(s);
	if (strct->num_print_ways == 0)
		strct->num_print_ways = 2147483647;
	strct->print_ways = 1;
	return (s);
}

char	*two_hach(char *s, int fd, t_str *strct)
{
	if (ft_strncmp(s, "##", 2) == 0)
	{
		if (ft_strncmp("##printways", s, ft_strlen(s)) == 0)
		{
			printways(strct, fd, s);
			return (s);
		}
		write_line(s, strct);
		ft_strdel(&s);
		get_next_line(fd, &s) == 0 ? ft_exit(strct) : 0;
		if (!s)
			ft_exit(strct);
		while (1)
		{
			if (s[0] != '#')
				break ;
			if (s[1] == '#' && s[2] != '#')
				s = comment_comand(s, strct, fd);
			ft_strdel(&s);
			get_next_line(fd, &s) == 0 ? ft_exit(strct) : 0;
			if (ft_strchr(s, '-') && !ft_strchr(s, ' '))
				ft_exit(strct);
		}
	}
	return (s);
}

char	*start(t_str *strct, char *s, int fd)
{
	if (strct->is_start == 1)
		ft_exit(strct);
	write_line(s, strct);
	ft_strdel(&s);
	get_next_line(fd, &s) == 0 ? ft_exit(strct) : 0;
	strct->room_name_start = ft_strdup(check_room(s, strct, fd));
	strct->is_start = 1;
	return (s);
}

char	*comment_comand(char *s, t_str *strct, int fd)
{
	if (ft_strncmp(s, "##start", ft_strlen(s)) == 0)
		s = start(strct, s, fd);
	else
	{
		if (ft_strncmp(s, "##end", ft_strlen(s)) == 0)
		{
			if (strct->is_end == 1)
				ft_exit(strct);
			write_line(s, strct);
			ft_strdel(&s);
			get_next_line(fd, &s) == 0 ? ft_exit(strct) : 0;
			strct->room_name_end = ft_strdup(check_room(s, strct, fd));
			strct->is_end = 1;
		}
		else
			s = two_hach(s, fd, strct);
	}
	write_line(s, strct);
	ft_strdel(&s);
	return (s);
}
