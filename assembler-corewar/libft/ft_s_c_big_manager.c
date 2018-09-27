/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c_big_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 03:49:00 by osapon            #+#    #+#             */
/*   Updated: 2018/03/04 03:49:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_width(t_option *data, int i)
{
	char			*sign;

	sign = ((data->flag & ZERO) == ZERO) ? ft_strdup("0") : ft_strdup(" ");
	ft_width_extra(data, i, sign);
	ft_strdel(&sign);
}

void				ft_s_c_big_manager(t_option *data)
{
	if (data->width > 0)
		ft_width(data, (int)ft_strlen(data->data));
}

void				ft_unidata(int num_byte, char **str, unsigned int uni)
{
	if (num_byte < 2)
		(*str)[0] = (char)uni;
	else if (num_byte < 3)
	{
		(*str)[0] = 192 | (uni >> 6);
		(*str)[1] = 128 | (uni & 63);
	}
	else if (num_byte < 4)
	{
		(*str)[0] = 224 | (uni >> 12);
		(*str)[1] = 128 | ((uni >> 6) & 63);
		(*str)[2] = 128 | (uni & 63);
	}
	else if (num_byte == 4)
	{
		(*str)[0] = 240 | (uni >> 18);
		(*str)[1] = 128 | ((uni >> 12) & 63);
		(*str)[2] = 128 | ((uni >> 6) & 63);
		(*str)[3] = 128 | (uni & 63);
	}
}

void				ft_data_manager(unsigned int uni, char **sample)
{
	int				num_byte;

	*sample = ft_strnew(4);
	num_byte = 1 + (uni > 0x7f) + (uni > 0x7ff) + (uni > 0xffff);
	ft_unidata(num_byte, sample, uni);
}

void				ft_s_c_parser(t_option *data, va_list *ap, int *count)
{
	unsigned int	*str;
	unsigned int	uni;

	if (data->conversion == C_UPPERCASE
		|| (data->conversion == C_LOWERCASE && data->size == L))
	{
		if ((uni = va_arg(*ap, unsigned int)) == 0)
			*count += ft_putchar(0);
		else
			ft_unichar_parse(data, uni);
	}
	else
	{
		if (!(str = va_arg(*ap, unsigned int*)))
			data->data = ft_strdup("(null)");
		else
			while (*str)
			{
				ft_unistr_parse(data, str);
				str++;
			}
	}
}
