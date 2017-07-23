/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:05:05 by mpotapov          #+#    #+#             */
/*   Updated: 2017/01/03 20:32:38 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_new_w(char const *s, int first, int i)
{
	char	*str;
	char	*dest;

	if (!(dest = ft_strnew(i - first + 1)))
		return (NULL);
	str = dest;
	while (i != first)
		*dest++ = *(char *)(s + first++);
	*dest = '\0';
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	**res;
	int		first;
	int		i;
	int		c_words;

	i = 0;
	if (!s)
		return (NULL);
	c_words = ft_count_w(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (c_words + 1))))
		return (NULL);
	res = arr;
	while (s[i] && c_words--)
	{
		while (s[i] == c && s[i])
			i++;
		first = i;
		while (s[i] != c && s[i])
			i++;
		*arr++ = ft_new_w(s, first, i);
	}
	*arr = 0;
	return (res);
}
