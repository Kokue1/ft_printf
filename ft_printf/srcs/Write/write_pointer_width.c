/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:35:05 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/17 23:42:28 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static void	ft_w_p_width(t_format *struct_)
{
	while (struct_->wid-- > 2)
	{
		write(1, " ", 1);
		struct_->len++;
	}
}

void	ft_write_pointer(t_format *struct_, char *trade)
{
	int	i;

	i = -1;
	struct_->wid -= (ft_strlen(trade) - 2);
	if (struct_->flag == '\0')
		ft_w_p_width(struct_);
	while (trade[++i])
	{
		write(1, &trade[i], 1);
		struct_->len++;
	}
	if (struct_->flag == '-')
		ft_w_p_width(struct_);
	struct_->flag = '\0';
	struct_->wid = 0;
}
