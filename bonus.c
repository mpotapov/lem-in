/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 21:01:44 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/22 15:32:16 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		cc(char *line)
{
	char *tmp;

	tmp = line;
	if (line[0] == '#' && line[1] != '#')
	{
		printf("%c%c%c%c ", 0x23, 0xE2, 0x83, 0xA3);
		tmp++;
		printf(GREY"%s"NO_COLOR"\n", tmp);
		ft_strdel(&line);
		return (1);
	}
	if (line[0] == '#' && line[1] == '#')
	{
		printf("%c%c%c%c ", 0x23, 0xE2, 0x83, 0xA3);
		tmp++;
		printf("%c%c%c%c ", 0x23, 0xE2, 0x83, 0xA3);
		tmp++;
		printf(RED"%s"NO_COLOR"\n", tmp);
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

void	print_minus(char *tmp)
{
	printf("%c%c%c%c ", 0xF0, 0x9F, 0x8F, 0xA0);
	while (*tmp)
	{
		if (*tmp == '-')
			printf("%c%c%c", 0xE2, 0x86, 0x94);
		else
			printf(YELLOW"%c"NO_COLOR, *tmp);
		tmp++;
	}
	printf("%c%c%c%c\n", 0xF0, 0x9F, 0x8F, 0xA0);
}

int		in(char *line)
{
	char *tmp;

	tmp = line;
	if (cc(line) == 1)
		return (1);
	if (ft_strchr(line, ' ') && line[0] != 'L')
	{
		printf("%c%c%c%c ", 0xF0, 0x9F, 0x8F, 0xA0);
		printf(BLUE"%s"NO_COLOR"\n", line);
		ft_strdel(&line);
		return (1);
	}
	if (ft_strchr(line, '-') && line[0] != 'L'
		&& line[0] != '[' && line[0] != 'W')
	{
		print_minus(tmp);
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

void	move(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'L')
			printf("%c%c%c%c ", 0xF0, 0x9F, 0x90, 0x9C);
		else if (line[i] == '-')
			printf(" %c%c%c ", 0xE2, 0x9E, 0xA1);
		else
			printf("%c", line[i]);
		i++;
	}
	printf("\n");
	ft_strdel(&line);
}

int		main(void)
{
	char *line;

	input();
	while (get_next_line(0, &line) > 0)
	{
		if (in(line) == 1)
			continue ;
		if (ft_strcmp(line, "ERROR") == 0)
		{
			er();
			continue ;
		}
		if (line[0] == 'L')
		{
			move(line);
			continue ;
		}
		printf("%s\n", line);
	}
	return (0);
}
