/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:04:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 13:04:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flag(char **format, t_option *data)
{
	while (**format == '#' || **format == '0' || **format == '+'
			|| **format == '-' || **format == ' ')
	{
		if (**format == '#')
			data->flag |= HASH;
		else if (**format == '0')
			data->flag |= ZERO;
		else if (**format == '-')
			data->flag |= MINUS;
		else if (**format == '+')
			data->flag |= PLUS;
		else if (**format == ' ')
			data->flag |= SPACE;
		(*format)++;
	}
}

static void	ft_width_and_precision(char **format, t_option *data)
{
	int		i;

	i = 0;
	while (ft_isdigit((*format)[i]))
		i++;
	data->width = ft_atoi(*format);
	*format += i;
	if (**format == '.')
	{
		data->dot = '.';
		(*format)++;
		i = 0;
		while (ft_isdigit((*format)[i]))
			i++;
		data->precision = ft_atoi(*format);
		if (data->precision == 0 && (**format == 's' || **format == 'S'
			|| **format == 'p' || **format == 'd' || **format == 'D'
			|| **format == 'i' || **format == 'o' || **format == 'O'
			|| **format == 'u' || **format == 'U' || **format == 'x'
			|| **format == 'X' || **format == 'c' || **format == 'C'))
			i = 0;
		else if (data->precision == 0 && (*format)[0] == '0')
			i = 1;
		*format += i;
	}
}

static void	ft_size(char **format, t_option *data)
{
	if (**format == 'z')
		data->size |= Z;
	else if (**format == 'j')
		data->size |= J;
	else if (**format == 'l' && (*format)[1] == 'l')
		data->size |= LL;
	else if (**format == 'l' && (*format)[1] != 'l')
		data->size |= L;
	else if (**format == 'h' && (*format)[1] != 'h')
		data->size |= H;
	else if (**format == 'h' && (*format)[1] == 'h')
		data->size |= HH;
	while (**format == 'h' || **format == 'l'
			|| **format == 'j' || **format == 'z')
		(*format)++;
}

static void	ft_conversion(char **format, t_option *data)
{
	if (**format == 's' || **format == 'S')
		data->conversion |= (**format == 's') ? S_LOWERCASE : S_UPPERCASE;
	else if (**format == 'p')
		data->conversion |= POINTER;
	else if (**format == 'd' || **format == 'D')
		data->conversion |= (**format == 'd') ? D_LOWERCASE : D_UPPERCASE;
	else if (**format == 'i')
		data->conversion |= INTEGER;
	else if (**format == 'o' || **format == 'O')
		data->conversion |= (**format == 'o') ? O_LOWERCASE : O_UPPERCASE;
	else if (**format == 'u' || **format == 'U')
		data->conversion |= (**format == 'u') ? U_LOWERCASE : U_UPPERCASE;
	else if (**format == 'x' || **format == 'X')
		data->conversion |= (**format == 'x') ? X_LOWERCASE : X_UPPERCASE;
	else if (**format == 'c' || **format == 'C')
		data->conversion |= (**format == 'c') ? C_LOWERCASE : C_UPPERCASE;
	else
		data->conversion = 0;
	if (data->conversion)
		(*format)++;
}

void		ft_parse_spec_structure(char **format, va_list *ap,
								int *count, t_option *data)
{
	data->width = 0;
	data->precision = 0;
	data->conversion = 0;
	data->flag = 0;
	data->size = 0;
	data->dot = 0;
	data->data = 0;
	(*format)++;
	ft_flag(format, data);
	if (ft_isdigit((**format)) || **format == '.')
		ft_width_and_precision(format, data);
	if (**format == 'z' || **format == 'j'
		|| **format == 'l' || **format == 'h')
		ft_size(format, data);
	ft_conversion(format, data);
	ft_parsing_data(ap, data, format, count);
	ft_managing_data(data);
	*count += ft_putstr(data->data);
	if (data->data)
		ft_strdel(&(data->data));
}
