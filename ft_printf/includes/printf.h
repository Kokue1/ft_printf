/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:47:09 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/20 19:32:34 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

# define TYPES "cspdiuxX%"
# define FLAGS "-0"
# define WIDTH "1234567890"
# define PRECISION "."
# define TWINKLETOES "*"

typedef float		t_decimal;

typedef struct s_format
{
	char	*format;
	int		len;
	int		count;
	int		wid;
	int		size;
	char	flag;
	int		precision;
    int     precis_aux;
	bool	precision2;
	char	twinkletoes;
	int		zeroflag;
	bool	free;
    bool    minus;
}					t_format;

int		ft_printf(const char *format, ...);

void	ft_write_char(t_format *struct_, va_list args);

void	ft_types(t_format *struct_, va_list args);

void	ft_write_percen(t_format *struct_);

void	ft_flags(t_format *struct_, va_list args);

void	ft_width(t_format *struct_, va_list args);

void	ft_verify_fwt(t_format *struct_, va_list args);

void	initialize(t_format *struct_, const char *format);

void	ft_minus_flag(t_format *struct_);

void	ft_zero_flag(t_format *struct_, va_list args);

void	ft_write_string(t_format *struct_, va_list args);

void	ft_precision(t_format *struct_, va_list args);

void	ft_write_string_with_nulls(t_format *struct_);

void	ft_treat_pointer(t_format *struct_, va_list args);

char	*ft_strjoinchr(char *s1, char s2);

void	ft_write_pointer(t_format *struct_, char *trade);

void    ft_integer(t_format *struct_, va_list args);

char    *ft_wsp(t_format *struct_, char *trade, char *temp);

char    *ft_z_cut_func(t_format *struct_, char *trade, char *temp);

char	*ft_pre_z(char *trade);

#endif
