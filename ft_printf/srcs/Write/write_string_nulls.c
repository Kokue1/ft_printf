/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string_nulls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:00:11 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/17 02:38:49 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

void	ft_write_string_minus_width_nulls(t_format *struct_)
{
	while (struct_->wid-- > 0)
	{
		write(1, " ", 1);
		struct_->len++;
	}
	struct_->flag = '\0';
}

void	ft_write_string_width_nulls(t_format *struct_)
{
	while (struct_->wid-- > 0)
	{
		write(1, " ", 1);
		struct_->len++;
	}
}

void	ft_write_string_with_nulls(t_format *struct_)
{
	if (struct_->precision >= 6 || struct_->precision <= -1)
	{
		struct_->wid -= 6;
		if (struct_->flag == '\0')
		{
			ft_write_string_width_nulls(struct_);
			write(1, "(null)", 6);
		}
		else if (struct_->flag == '-')
		{
			write(1, "(null)", 6);
			ft_write_string_minus_width_nulls(struct_);
		}
		struct_->len += 6;
	}
	else
	{
		if (struct_->flag == '\0')
			ft_write_string_width_nulls(struct_);
		else if (struct_->flag == '-')
			ft_write_string_minus_width_nulls(struct_);
	}
}
