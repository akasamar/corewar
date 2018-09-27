/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:24:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/26 17:24:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** FLAGS DEFINE;
*/

# define HASH 1
# define ZERO 2
# define PLUS 4
# define MINUS 8
# define SPACE 16

/*
** SIZE TYPE DEFINE;
*/

# define HH 1
# define H 2
# define L 4
# define LL 8
# define J 16
# define Z 32

/*
** CONVERSIONS DEFINE;
*/

# define S_LOWERCASE 1
# define S_UPPERCASE 2
# define POINTER 3
# define D_LOWERCASE 4
# define D_UPPERCASE 5
# define INTEGER 6
# define O_LOWERCASE 7
# define O_UPPERCASE 8
# define U_LOWERCASE 9
# define U_UPPERCASE 10
# define X_LOWERCASE 11
# define X_UPPERCASE 12
# define C_LOWERCASE 13
# define C_UPPERCASE 14

/*
** ADDITIONAL LIBS;
*/

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_option
{
	char		flag;
	char		size;
	char		conversion;
	char		c;
	char		dot;
	int			width;
	int			precision;
	char		*data;
}				t_option;

void			ft_unichar_parse(t_option *data, unsigned int uni);
void			ft_unistr_parse(t_option *data, const unsigned int *str);
void			ft_s_c_parser(t_option *data, va_list *ap, int *count);
void			ft_data_manager(unsigned int uni, char **sample);
int				ft_size_t_check(char conversion, char size);
int				ft_j_check(char conversion, char size);
int				ft_long_long_check(char conversion, char size);
int				ft_long_check(char conversion, char size);
int				ft_int_check(char conversion, char size);
int				ft_short_check(char conversion, char size);
int				ft_char_check(char conversion, char size);
void			ft_size_t_pars(va_list *ap, t_option *data);
void			ft_long_long_pars(va_list *ap, t_option *data);
void			ft_long_pars(va_list *ap, t_option *data);
void			ft_int_pars(va_list *ap, t_option *data);
void			ft_short_pars(va_list *ap, t_option *data);
void			ft_char_pars(va_list *ap, t_option *data, int *count);
void			ft_width_extra(t_option *data, int i, char *sign);
void			ft_null_manager(t_option *data);
void			ft_o_manager(t_option *data);
void			ft_s_c_big_manager(t_option *data);
void			ft_s_c_small_manager(t_option *data);
void			ft_xbig_manager(t_option *data);
void			ft_xsmall_manager(t_option *data);
void			ft_decemal_manager(t_option *data);
void			ft_managing_data(t_option *data);
void			ft_parsing_data(va_list *ap, t_option *data,\
								char **format, int *count);
void			ft_parse_spec_structure(char **format,\
				va_list *ap, int *count, t_option *data);
int				ft_printf(const char *format, ...);

#endif
