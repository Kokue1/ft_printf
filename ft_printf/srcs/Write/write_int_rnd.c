/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int_rnd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:02:40 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/21 02:03:54 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

char    *ft_wsp(t_format *struct_, char *trade, char *temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	struct_->zeroflag -= ft_strlen(trade);
	while (struct_->zeroflag-- > 0)
		temp[i++] = ' ';
	while (trade[j])
		temp[i++] = trade[j++];
	temp[i] = '\0';
	struct_->zeroflag = 0;
	free(trade);
	return (temp);
}

char    *ft_z_cut_func(t_format *struct_, char *trade, char *temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (trade[0] == '-')
	{
		struct_->zeroflag -= (int)(ft_strlen(trade) - 1);
		temp[i++] = '-';
		struct_->zeroflag--;
		j++;
	}
	else
		struct_->zeroflag -= (int)ft_strlen(trade);
	while (struct_->zeroflag-- > 0)
		temp[i++] = '0';
	while (trade[j])
		temp[i++] = trade[j++];
	temp[i] = '\0';
	struct_->zeroflag = 0;
	free(trade);
	return (temp);
}

char	*ft_pre_z(char *trade)
{
	char    *temp;

	temp = ft_strdup("");
	free(trade);
	return (temp);
}