/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:24:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/26 17:24:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_unichar_parse(t_option *data, unsigned int uni)
{
	char			*tmp;
	char			*sample;

	tmp = data->data;
	ft_data_manager(uni, &sample);
	data->data = ft_strjoin(tmp, sample);
	ft_strdel(&sample);
	ft_strdel(&tmp);
}

void				ft_unistr_parse(t_option *data, const unsigned int *str)
{
	unsigned int	uni;
	char			*tmp;
	char			*sample;

	uni = *str;
	tmp = data->data;
	ft_data_manager(uni, &sample);
	data->data = ft_strjoin(tmp, sample);
	ft_strdel(&sample);
	ft_strdel(&tmp);
}

void				ft_parsing_data(va_list *ap, t_option *data,\
								char **format, int *count)
{
	if (ft_char_check(data->conversion, data->size))
		ft_char_pars(ap, data, count);
	else if (ft_short_check(data->conversion, data->size))
		ft_short_pars(ap, data);
	else if (ft_int_check(data->conversion, data->size))
		ft_int_pars(ap, data);
	else if (ft_long_check(data->conversion, data->size))
		ft_long_pars(ap, data);
	else if (ft_long_long_check(data->conversion, data->size))
		ft_long_pars(ap, data);
	else if (ft_j_check(data->conversion, data->size))
		ft_long_long_pars(ap, data);
	else if (ft_size_t_check(data->conversion, data->size))
		ft_size_t_pars(ap, data);
	else
	{
		while (ft_isspace(**format))
			(*format)++;
		data->data = ft_strnew(0);
		data->data = ft_strncpy(data->data, *format, 1);
		(*format)++;
	}
}

void				ft_managing_data(t_option *data)
{
	if (data->conversion && data->dot == '.'
		&& data->precision == 0 && data->data && data->data[0] == '0')
	{
		ft_strdel(&data->data);
		data->data = ft_strdup("");
		ft_null_manager(data);
	}
	else if (data->conversion == X_LOWERCASE || data->conversion == POINTER)
		ft_xsmall_manager(data);
	else if (data->conversion == X_UPPERCASE)
		ft_xbig_manager(data);
	else if (data->conversion == D_LOWERCASE || data->conversion == D_UPPERCASE
			|| data->conversion == INTEGER)
		ft_decemal_manager(data);
	else if (data->conversion == S_LOWERCASE || data->conversion == C_LOWERCASE)
		ft_s_c_small_manager(data);
	else if (data->conversion == S_UPPERCASE || data->conversion == C_UPPERCASE
			|| (data->conversion == S_LOWERCASE && data->size == L)
			|| (data->conversion == C_LOWERCASE && data->size == L))
		ft_s_c_big_manager(data);
	else if (data->conversion == O_LOWERCASE || data->conversion == O_UPPERCASE)
		ft_o_manager(data);
	else if (data->conversion == U_LOWERCASE || data->conversion == U_UPPERCASE
			|| !data->conversion)
		ft_null_manager(data);
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	t_option		data;
	int				count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if ((*format == '%' && format[1] != '%')
			&& (*format == '%' && format[1] != '\0'))
			ft_parse_spec_structure((char **)&format, &ap, &count, &data);
		else if (*format == '%' && (format[1] == '%' || format[1] == '\0'))
		{
			format++;
			if (*format != '\0')
				count += ft_putchar(*format++);
		}
		else
			count += ft_putchar(*format++);
	}
	va_end(ap);
	return (count);
}
