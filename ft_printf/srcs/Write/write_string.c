/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:35:05 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/17 23:53:22 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static void	ft_write_string_minus_width(t_format *struct_,
							char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		struct_->len++;
		i++;
	}
	while (struct_->wid-- > 0)
	{
		write(1, " ", 1);
		struct_->len++;
	}
	struct_->flag = '\0';
}

static void	ft_write_string_width(t_format *struct_, char *str)
{
	int	i;

	i = 0;
	while (struct_->wid-- > 0)
	{
		write(1, " ", 1);
		struct_->len++;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		struct_->len++;
		i++;
	}
}

static char	*ft_verify_precision(t_format *struct_, char *str)
{
	if (struct_->precision < 0 || struct_->precision > (int)ft_strlen(str))
		return (str);
	else
		str = ft_substr(str, 0, struct_->precision);
	struct_->precision = -1;
	struct_->free = true;
	return (str);
}

static void	ft_write_string2(t_format *struct_, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		struct_->len++;
		i++;
	}
}

void	ft_write_string(t_format *struct_, va_list args)
{
	char	*str;

	struct_->free = false;
	str = va_arg(args, char *);
	if (str == NULL)
		ft_write_string_with_nulls(struct_);
	else
	{
		str = ft_verify_precision(struct_, str);
		struct_->wid -= ft_strlen(str);
		if (struct_->flag == '\0')
			ft_write_string_width(struct_, str);
		else if (struct_->flag == '-')
			ft_write_string_minus_width(struct_, str);
		else
			ft_write_string2(struct_, str);
	}
	struct_->wid = 0;
	if (struct_->free)
		free(str);
}
