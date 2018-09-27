/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:07:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 13:07:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_char_exe(t_option *data, va_list *ap, int *count)
{
	char	*str;
	char	sign;
	int		i;

	i = 1;
	if (!(str = ft_itoa(va_arg(*ap, int))))
		return (NULL);
	if (str[0] == '0')
	{
		sign = (char)(((data->flag & ZERO) == ZERO) ? '0' : ' ');
		while (i++ < data->width)
			*count += ft_putchar(sign);
		*count += ft_putchar(0);
		ft_strdel(&str);
		return (str);
	}
	return (str);
}

void		ft_char_pars(va_list *ap, t_option *data, int *count)
{
	if (data->conversion == C_LOWERCASE)
		data->data = ft_char_exe(data, ap, count);
	else if (data->conversion == D_LOWERCASE || data->conversion == INTEGER)
		data->data = ft_itoa((char)va_arg(*ap, int));
	else if (data->conversion == S_LOWERCASE)
		data->data = ft_strdup(va_arg(*ap, char*));
	else if (data->conversion == O_LOWERCASE)
		data->data = ft_itoa_base((unsigned char)va_arg(*ap, unsigned int), 8);
	else if (data->conversion == X_LOWERCASE || data->conversion == X_UPPERCASE)
		data->data = ft_itoa_base((unsigned char)va_arg(*ap, unsigned int), 16);
	else if (data->conversion == C_UPPERCASE || data->conversion == S_UPPERCASE
			|| (data->conversion == C_LOWERCASE && data->size == L)
			|| (data->conversion == S_LOWERCASE && data->size == L))
		ft_s_c_parser(data, ap, count);
	else
		data->data = ft_uitoa((unsigned char)va_arg(*ap, unsigned int));
}

void		ft_short_pars(va_list *ap, t_option *data)
{
	if (data->conversion == D_LOWERCASE || data->conversion == INTEGER)
		data->data = ft_itoa((short)va_arg(*ap, int));
	else if (data->conversion == X_LOWERCASE || data->conversion == X_UPPERCASE)
		data->data = ft_itoa_base((unsigned short)va_arg(*ap, unsigned int),\
		16);
	else if (data->conversion == O_LOWERCASE)
		data->data = ft_itoa_base((unsigned short)va_arg(*ap, unsigned int), 8);
	else
		data->data = ft_itoa_base((unsigned short)va_arg(*ap, unsigned int),\
		10);
}

void		ft_int_pars(va_list *ap, t_option *data)
{
	if (data->conversion == D_LOWERCASE || data->conversion == INTEGER)
		data->data = ft_itoa(va_arg(*ap, int));
	else if (data->conversion == U_LOWERCASE)
		data->data = ft_uitoa(va_arg(*ap, unsigned int));
	else if (data->conversion == O_LOWERCASE)
		data->data = ft_uitoa_base(va_arg(*ap, unsigned int), 8);
	else if (data->conversion == X_LOWERCASE || data->conversion == X_UPPERCASE)
		data->data = ft_uitoa_base(va_arg(*ap, unsigned int), 16);
}

void		ft_long_pars(va_list *ap, t_option *data)
{
	if (data->conversion == D_LOWERCASE || data->conversion == INTEGER
		|| data->conversion == D_UPPERCASE)
		data->data = ft_ltoa(va_arg(*ap, long));
	else if (data->conversion == O_LOWERCASE || data->conversion == O_UPPERCASE)
		data->data = ft_ulltoa_base(va_arg(*ap, unsigned long), 8);
	else if (data->conversion == X_LOWERCASE || data->conversion == X_UPPERCASE)
		data->data = ft_ulltoa_base(va_arg(*ap, unsigned long), 16);
	else if (data->conversion == POINTER)
		data->data = ft_ulltoa_base(va_arg(*ap, unsigned long), 16);
	else
		data->data = ft_ultoa(va_arg(*ap, unsigned long));
}
