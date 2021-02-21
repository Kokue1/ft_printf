/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 20:38:53 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/21 21:29:00 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static int	ft_strlen_uns(long long arg)
{
	int		i;

	i = 0;
	if (arg == 0)
		return (2);
	if (arg < 0)
	{
		arg *= -1;
		i++;
	}
	while (arg > 9)
	{
		arg = arg / 10;
		i++;
	}
	return (i + 2);
}

static char	*minus_zero(long long arg)
{
	char		*result;
	int			i;
	int			j;
	long long	remainder;

	i = ft_strlen_uns(arg) - 1;
	arg *= -1;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	result[0] = '-';
	while (arg > 0)
	{
		remainder = arg % 10;
		result[i--] = remainder + '0';
		arg = arg / 10;
		j++;
	}
	result[j] = '\0';
	return (result);
}

static char	*more_zero(long long arg)
{
	char		*result;
	int			i;
	int			j;
	long long	remainder;

	i = ft_strlen_uns(arg) - 2;
	j = 0;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	while (arg > 0)
	{
		remainder = arg % 10;
		result[i--] = remainder + '0';
		arg = arg / 10;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_itoa_uns(long long arg)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	if (arg == 0)
	{
		result = malloc(sizeof(char *) * 2);
		if (!result)
			return (NULL);
		result[i++] = '0';
		result[i] = '\0';
	}
	else if (arg < 0)
		result = minus_zero(arg);
	else
		result = more_zero(arg);
	return (result);
}
