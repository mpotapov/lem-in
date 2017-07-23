/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:45:50 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/22 15:27:36 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*num_of_ants_comment(char *line, int fd, t_str *strct)
{
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '#' && line[1] != '#')
			line = comment_comand(line, strct, fd);
		else
			break ;
	}
	return (line);
}

int		num_of_ants(char *line, char *s, t_str *strct)
{
	int fd;
	int i;

	i = 0;
	fd = 0;
	line = num_of_ants_comment(line, fd, strct);
	line == NULL ? ft_exit(strct) : 0;
	write_line(line, strct);
	strct->num_ants = ft_atoi(line);
	if (strct->num_ants <= 0 && strct->is_links == 0)
		ft_exit(strct);
	while (line[i])
		if (ft_isdigit(line[i++]) == 0 && strct->is_links == 0)
			ft_exit(strct);
	if (i > 10 && strct->is_links == 0)
		ft_exit(strct);
	if (i == 10)
		if (line[0] - '0' >= 3 && strct->is_links == 0)
			ft_exit(strct);
	ft_strdel(&line);
	return (fd);
}

void	ft_read(char *s, t_str *strct)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = num_of_ants(line, s, strct);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, "") == 0 && strct->is_links == 0)
			ft_exit(strct);
		if (ft_strncmp(line, "#", 1) == 0)
		{
			line = comment_comand(line, strct, fd);
			continue ;
		}
		if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
			strct->is_links = 1;
		strct->is_links == 0 ? check_room(line, strct, fd)
			: check_link(line, strct);
		write_line(line, strct);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	to_null(t_str *strct)
{
	strct->is_links = 0;
	strct->num_ants = 0;
	strct->is_start = 0;
	strct->is_end = 0;
	strct->count_rooms = 0;
	strct->room_name = NULL;
	strct->room_name_start = NULL;
	strct->room_name_end = NULL;
	strct->is_matrix = 0;
	strct->end_read = 0;
	strct->print_ways = -1;
}

int		main(int ac, char **av)
{
	t_str	strct;

	ac == 1 ? 1 : ft_exit(&strct);
	to_null(&strct);
	ft_read(av[2], &strct);
	if (strct.is_start == 0 || strct.is_end == 0)
		ft_exit(&strct);
	write(1, strct.line_print, ft_strlen(strct.line_print));
	write(1, "\n", 1);
	alg(&strct);
	return (0);
}
