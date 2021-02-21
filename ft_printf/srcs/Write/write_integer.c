/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:29:14 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/21 17:16:53 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static char	*ft_write_w_m(t_format *struct_, char *trade)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (struct_->wid < (int)ft_strlen(trade))
		return (trade);
	struct_->wid -= (int)ft_strlen(trade);
	temp = malloc(sizeof(char) * ((int)ft_strlen(trade) + struct_->wid + 1));
	if (temp == NULL)
		return (NULL);
	while (trade[j])
		temp[i++] = trade[j++];
	while (struct_->wid-- > 0)
		temp[i++] = ' ';
	temp[i] = '\0';
	struct_->wid = 0;
	free(trade);
	struct_->flag = '\0';
	return (temp);
}

static char	*ft_write_w(t_format *struct_, char *trade)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (struct_->wid < (int)ft_strlen(trade))
		return (trade);
	struct_->wid -= (int)ft_strlen(trade);
	temp = malloc(sizeof(char) * ((int)ft_strlen(trade) + struct_->wid + 1));
	if (temp == NULL)
		return (NULL);
	while (struct_->wid-- > 0)
		temp[i++] = ' ';
	while (trade[j])
		temp[i++] = trade[j++];
	temp[i] = '\0';
	struct_->wid = 0;
	struct_->flag = '\0';
	free(trade);
	return (temp);
}

static char	*ft_write_zero(t_format *struct_, char *trade)
{
	char	*temp;

	if (struct_->zeroflag < 0 || struct_->zeroflag < (int)ft_strlen(trade))
		return (trade);
	temp = malloc(sizeof(char) * ((int)ft_strlen(trade) + struct_->zeroflag + 1));
	if (temp == NULL)
		return (NULL);
	if (struct_->zeroflag > struct_->precis_aux && struct_->precis_aux > -1)
	{
		temp = ft_wsp(struct_, trade, temp);
		return (temp);
	}
	temp = ft_z_cut_func(struct_, trade, temp);
	return (temp);
}

static char	*ft_verify_p_id(t_format *struct_, char *trade)
{
	char	*temp;
	int		len;

	if (struct_->precision < 0 || struct_->precision < (int)ft_strlen(trade))
		return (trade);
	ft_verify_p_it(struct_, trade);
	len = (int)ft_strlen(trade) + struct_->precision + 1;
	temp = malloc(sizeof(char) * (len));
	if (temp == NULL)
		return (NULL);
	temp = ft_write_p_it(struct_, trade, temp);
	return (temp);
}

void	ft_integer(t_format *struct_, va_list args)
{
	char	*trade;
	int		arg;
	int		len;

	arg = va_arg(args, int);
	trade = ft_itoa(arg);
	struct_->precis_aux = struct_->precision;
	if (struct_->precision == 0)
		trade = ft_pre_z(trade);
	else
		trade = ft_verify_p_id(struct_, trade);
	if (struct_->flag == '0')
		trade = ft_write_zero(struct_, trade);
	if (struct_->flag == '-')
		trade = ft_write_w_m(struct_, trade);
	else
		trade = ft_write_w(struct_, trade);
	len = (int)ft_strlen(trade);
	write(1, trade, len);
	struct_->len += len;
	struct_->minus = false;
	struct_->wid = -1;
	free(trade);
}
