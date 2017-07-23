/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:49:01 by mpotapov          #+#    #+#             */
/*   Updated: 2017/05/05 17:55:53 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	long int		num;
	int				minus_f;
	int				i;

	i = 0;
	minus_f = 0;
	num = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '0') ||
		(*str == '\n') || (*str == '\f') || (*str == '\v') || (*str == '\r'))
	{
		if (*str == '0' && !ft_isdigit(*(str + 1)))
			break ;
		str++;
	}
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			minus_f = 1;
	while (str[i] <= 57 && str[i] >= 48)
	{
		num = num + (str[i] - '0');
		if (str[i + 1] <= 57 && str[i + 1] >= 48)
			num = num * 10;
		i++;
	}
	return (minus_f ? -num : num);
}
