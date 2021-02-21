/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:09:18 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/20 19:18:24 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

void	ft_minus_flag(t_format *struct_)
{
	char	temp;

    if (struct_->flag == '0')
    {
        struct_->flag = '-';
        while (!(ft_strchr(TYPES, struct_->format[struct_->count])
        || ft_strchr(PRECISION, struct_->format[struct_->count])
        || ft_strchr(WIDTH, struct_->format[struct_->count])))
        {
            struct_->count++;
        }
        struct_->count -= 1;
        return ;
    }
	temp = struct_->format[struct_->count];
	while (ft_strchr(FLAGS, struct_->format[struct_->count]))
		struct_->count++;
	struct_->flag = temp;
	struct_->count -= 1;
}
