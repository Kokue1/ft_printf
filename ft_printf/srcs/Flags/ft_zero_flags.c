/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:09:18 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/21 02:04:15 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static void	ft_star(t_format *struct_, va_list args)
{
	struct_->zeroflag = va_arg(args, int);
	if (struct_->zeroflag < 0)
	{
		struct_->wid *= (struct_->zeroflag * - 1);
		struct_->zeroflag = 0;
	}
}

static bool	ft_verify_star(t_format *struct_)
{
	if (ft_strchr(TWINKLETOES, struct_->format[struct_->count]))
	{
		struct_->twinkletoes = '*';
		return (true);
	}
	return (false);
}

void	ft_zero_flag(t_format *struct_, va_list args)
{
	char    *temp;
	char	*temp2;
	int		number;

	struct_->flag = struct_->format[struct_->count++];
	if (ft_verify_star(struct_))
	{
		ft_star(struct_, args);
		return ;
	}	
	if (struct_->format[struct_->count--] == '-')
		return ;
	temp = NULL;
	while (ft_isdigit(struct_->format[struct_->count]))
	{
		number = struct_->format[struct_->count] - 48;
		temp2 = ft_itoa(number);
		if (!temp)
			temp = ft_strdup(temp2);
		else
			temp = ft_strjoin(temp, temp2);
		free(temp2);
		struct_->count++;
	}
	struct_->zeroflag = ft_atoi(temp);
	free(temp);
	struct_->count -= 1;
}
