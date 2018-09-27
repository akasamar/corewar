/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:01:00 by osapon            #+#    #+#             */
/*   Updated: 2018/03/04 00:01:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_minus_width(t_option *data, int i)
{
	char	*str;

	if (i > data->precision && data->precision != 0)
	{
		ft_memset(&(data->data[data->precision]), 0, i - data->precision);
		i -= (i - data->precision);
	}
	while (i++ < data->width)
	{
		str = data->data;
		data->data = ft_strjoin(str, " ");
		ft_strdel(&str);
	}
}

static void	ft_width(t_option *data, int i)
{
	char	*sign;

	sign = ((data->flag & ZERO) == ZERO) ? ft_strdup("0") : ft_strdup(" ");
	if ((i > data->precision && data->precision != 0))
	{
		ft_memset(&(data->data[data->precision]), 0, i - data->precision);
		i -= (i - data->precision);
	}
	if (data->dot && !data->flag && data->width > 0
		&& data->conversion == S_LOWERCASE && data->precision == 0)
	{
		ft_memset(&(data->data[data->precision]), 0, i - data->precision);
		i -= (i - data->precision);
	}
	if ((data->flag & MINUS) == MINUS)
		ft_minus_width(data, i);
	else
		ft_width_extra(data, i, sign);
	ft_strdel(&sign);
}

void		ft_width_extra(t_option *data, int i, char *sign)
{
	char	*str;

	while (i++ < data->width)
	{
		str = data->data;
		data->data = ft_strjoin(sign, str);
		ft_strdel(&str);
	}
}

void		ft_s_c_small_manager(t_option *data)
{
	int		i;

	if (!data->data && data->width == 0)
		data->data = ft_strdup("(null)");
	if (data->conversion == C_LOWERCASE && data->data)
	{
		data->c = (char)ft_atoi(data->data);
		data->data[0] = data->c;
		ft_bzero(&(data->data[1]), ft_strlen(&(data->data[1])));
	}
	i = (data->data) ? (int)ft_strlen(data->data) : 0;
	if (data->width > 0 && (data->flag & MINUS) != MINUS && data->data)
		ft_width(data, i);
	else if (data->width > 0 && (data->flag & MINUS) == MINUS && data->data)
		ft_minus_width(data, i);
	else if (data->precision > 0)
		ft_width(data, i);
	if (data->width > 0 && (data->flag & ZERO) == ZERO && data->data == NULL
		&& data->conversion == S_LOWERCASE)
		ft_width(data, 0);
}
