/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_rnd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:02:40 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/21 20:18:50 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

char	*ft_wsp_ud(t_format *struct_, char *trade, char *temp)
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

char	*ft_z_cut_func_ud(t_format *struct_, char *trade, char *temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
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

char	*ft_pre_z_ud(char *trade)
{
	char	*temp;

	temp = ft_strdup("");
	free(trade);
	return (temp);
}

void	ft_verify_p_it_ud(t_format *struct_, char *trade)
{
	struct_->precision -= (int)ft_strlen(trade);
}

char	*ft_write_p_it_ud(t_format *struct_, char *trade, char *temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (struct_->precision-- > 0)
		temp[i++] = '0';
	while (trade[j])
		temp[i++] = trade[j++];
	temp[i] = '\0';
	struct_->precision = -1;
	free(trade);
	return (temp);
}
