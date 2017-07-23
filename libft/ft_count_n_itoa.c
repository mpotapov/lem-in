/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_n_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:16:27 by mpotapov          #+#    #+#             */
/*   Updated: 2017/05/05 17:56:30 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_n_itoa_ullb(unsigned long long int n)
{
	int num;

	num = 0;
	while (n != 0)
	{
		num++;
		n = n / 10;
	}
	return (num);
}

int		ft_count_n_itoa(int n)
{
	int num;

	num = 0;
	if (n <= 0)
		num++;
	while (n != 0)
	{
		num++;
		n = n / 10;
	}
	return (num);
}
