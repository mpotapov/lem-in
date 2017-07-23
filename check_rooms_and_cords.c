/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms_and_cords.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:35:52 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/22 13:36:17 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_cords2(t_str *strct, int *tmp, int i)
{
	tmp[i] = (int)strct->x_cord;
	tmp[i + 1] = (int)strct->y_cord;
	free(strct->cords);
	strct->cords = tmp;
}

void	check_cords(t_str *strct)
{
	int	*tmp;
	int	i;

	if (strct->count_rooms == 1)
	{
		strct->cords = (int *)malloc(sizeof(int) * 2);
		strct->cords[0] = (int)strct->x_cord;
		strct->cords[1] = (int)strct->y_cord;
		return ;
	}
	tmp = (int *)malloc(sizeof(int) * strct->count_rooms * 2);
	i = 0;
	while (i < strct->count_rooms * 2 - 2)
	{
		tmp[i] = strct->cords[i];
		i++;
	}
	i = 0;
	while (i < strct->count_rooms * 2 - 2)
	{
		if (tmp[i] == strct->x_cord && tmp[i + 1] == strct->y_cord)
			ft_exit(strct);
		i += 2;
	}
	check_cords2(strct, tmp, i);
}

void	check_int(char *s, long int x, t_str *strct)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != ' ')
		i++;
	s[0] == '-' ? i-- : 0;
	i > 10 ? ft_exit(strct) : 0;
	if (x < -2147483648 || x > 2147483647)
		ft_exit(strct);
}

void	check_room2(char *s, t_str *strct, int i, int j)
{
	char	*tmp;

	tmp = s;
	ft_strdel(&strct->room_name);
	strct->room_name = (char *)malloc(sizeof(char) * i + 1);
	ft_strncpy(strct->room_name, s, (size_t)i);
	strct->room_name[i] = '\0';
	while (j < strct->count_rooms - 1)
		if (ft_strncmp(strct->rooms[j++], s, (size_t)i) == 0)
			ft_exit(strct);
	tmp = tmp + ++i;
	strct->x_cord = ft_atoi(tmp);
	check_int(tmp, strct->x_cord, strct);
	while (s[i++] != ' ')
		if (ft_isdigit(s[i - 1]) == 0 && s[i - 1] != '-')
			ft_exit(strct);
	tmp = s + i;
	strct->y_cord = ft_atoi(tmp);
	check_int(tmp, strct->y_cord, strct);
	while (s[i++])
		if (ft_isdigit(s[i - 1]) == 0 && s[i - 1] != '-')
			ft_exit(strct);
	check_cords(strct);
	to_big(strct);
}

char	*check_room(char *s, t_str *strct, int fd)
{
	int		i;

	i = 0;
	while (1)
	{
		if (s[0] == '#')
		{
			s = comment_comand(s, strct, fd);
			get_next_line(fd, &s) == 0 ? ft_exit(strct) : 0;
		}
		else
			break ;
	}
	strct->count_rooms++;
	if (strct->is_links == 1 || s[0] == 'L')
		ft_exit(strct);
	while (s[i] != ' ' && s[i] != '\0')
	{
		if (ft_isalpha(s[i]) == 0 && ft_isdigit(s[i]) == 0)
			ft_exit(strct);
		i++;
	}
	s[i] == '\0' ? ft_exit(strct) : 0;
	check_room2(s, strct, i, 0);
	return (strct->room_name);
}
