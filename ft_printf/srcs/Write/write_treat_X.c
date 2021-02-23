/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_treat_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:13:16 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/23 19:55:22 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static char	*ft_reversecard(char *trade)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(trade) - 1;
	temp = malloc(sizeof(char) * (j + 2));
	if (!temp)
		return (NULL);
	while (j >= 0)
	{
		temp[i] = trade[j];
		j--;
		i++;
	}
	temp[i] = '\0';
	free(trade);
	return (temp);
}

static char	*ft_easy_return(char *trade, long long int result)
{
	char	*temp;

	temp = ft_itoa(result);
	trade = ft_strjoin(trade, temp);
	free(temp);
	return (trade);
}

static char	*cnvrt_hexa(t_format *struct_,
						long long int hexa, char *trade)
{
	long long int	remainder;
	int				quoficient;

	struct_->free = true;
	if (hexa < 10 && hexa > -1)
		return (trade = ft_easy_return(trade, hexa));
	remainder = hexa % 16;
	while (hexa > 9)
	{
		if (remainder > 9)
		{
			quoficient = remainder + 87;
			trade = ft_strjoinchr(trade, quoficient);
		}
		else
			trade = ft_strjoinchr(trade, (remainder + 48));
		hexa = hexa / 16;
		remainder = hexa % 16;
	}
	if (hexa)
		trade = ft_strjoinchr(trade, (remainder + 48));
	trade = ft_reversecard(trade);
	return (trade);
}

void	ft_treat_hexa_u(t_format *struct_, va_list args)
{
	long long int	hexa;
	char			*trade;
	int i = 0;

	struct_->free = false;
	hexa = va_arg(args, unsigned int);
	trade = ft_strdup("");
	trade = cnvrt_hexa(struct_, hexa, trade);
	ft_write_hexa_u(struct_, trade);
}
