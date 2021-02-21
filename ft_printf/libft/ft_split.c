/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 01:33:52 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/21 20:19:27 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_c(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s++ == c)
			continue ;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	t_split	val;

	val.j = 0;
	if (!s)
		return (NULL);
	val.big_new = malloc(sizeof(char *) * (count_c(s, c) + 1));
	if (!(val.big_new))
		return (NULL);
	val.i = 0;
	val.start = 0;
	while ((s[val.start + val.i] != 0) && (count_c(s, c) > 0))
	{
		while (s[val.start] == c)
			val.start++;
		while (s[val.start + val.i] != c && s[val.start + val.i] != '\0')
			val.i++;
		val.big_new[val.j++] = ft_substr(s, val.start, val.i);
		while (s[val.start + val.i] == c && s[val.start + val.i] != '\0')
			val.i++;
		val.temp = (char *)s + val.i;
		s = val.temp;
		val.i = 0;
	}
	val.big_new[val.j] = 0;
	return (val.big_new);
}
