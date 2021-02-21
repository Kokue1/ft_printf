/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:35:05 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/17 15:56:21 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static char	*ft_pointer_precision(t_format *struct_, char *trade)
{
	int		i;
	int		j;
	char	*len;

	i = 2;
	j = 2;
	struct_->free = true;
	struct_->precision -= (ft_strlen(trade) - 2);
	len = malloc(sizeof(char) * (ft_strlen(trade) + struct_->precision + 1));
	if (!len)
		return (NULL);
	len[0] = '0';
	len[1] = 'x';
	while (struct_->precision-- > 0)
		len[i++] = '0';
	while (trade[j])
		len[i++] = trade[j++];
	len[i] = '\0';
	struct_->precision = -1;
	free(trade);
	return (len);
}

static char	*ft_reversecard(char *trade)
{
	char	*temp;
	int		i;
	int		j;

	i = 2;
	j = ft_strlen(trade) - 1;
	temp = malloc(sizeof(char) * (j + 2));
	if (temp == NULL)
		return (NULL);
	temp[0] = '0';
	temp[1] = 'x';
	while (trade[j] != 'x')
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
						long long int point, char *trade)
{
	long long int	result;
	long long int	remainder;
	int				quoficient;

	struct_->free = true;
	result = point;
	if (result >= 0 && result < 10)
		return (ft_easy_return(trade, result));
	remainder = result % 16;
	while (result >= 10)
	{
		if (remainder >= 10)
		{
			quoficient = remainder + 87;
			trade = ft_strjoinchr(trade, quoficient);
		}
		else
			trade = ft_strjoinchr(trade, (remainder + 48));
		result = result / 16;
		remainder = result % 16;
	}
	if (result)
		trade = ft_strjoinchr(trade, (result + 48));
	trade = ft_reversecard(trade);
	return (trade);
}

void	ft_treat_pointer(t_format *struct_, va_list args)
{
	long long int	point;
	char			*trade;

	struct_->free = false;
	point = va_arg(args, long long int);
	if (point == '\0')
	{
		trade = ft_strdup("0x0");
		struct_->free = true;
		struct_->precision2 = false;
	}
	else
	{
		trade = ft_strdup("0x");
		trade = cnvrt_hexa(struct_, point, trade);
	}
	if (struct_->precision > (int)(ft_strlen(trade) - 2)
		&& struct_->precision2 != false)
		trade = ft_pointer_precision(struct_, trade);
	ft_write_pointer(struct_, trade);
	struct_->precision2 = true;
	if (struct_->free)
		free(trade);
}
