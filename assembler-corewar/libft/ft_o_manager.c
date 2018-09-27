/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 02:09:00 by osapon            #+#    #+#             */
/*   Updated: 2018/03/04 02:09:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hash(t_option *data)
{
	char	*str;

	str = data->data;
	data->data = ft_strjoin("0", str);
	ft_strdel(&str);
}

static void	ft_precision(t_option *data, int i)
{
	char	*str;

	while (i++ < data->precision)
	{
		str = data->data;
		data->data = ft_strjoin("0", str);
		ft_strdel(&str);
	}
}

static void	ft_minus_width(t_option *data, int i)
{
	char	*str;

	if ((data->flag & HASH) == HASH && data->data[0] != '0')
		ft_hash(data);
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
	ft_width_extra(data, i, sign);
	ft_strdel(&sign);
}

void		ft_o_manager(t_option *data)
{
	if ((data->flag & HASH) == HASH && data->data[0] != '0')
		ft_hash(data);
	if (data->precision > 0)
		ft_precision(data, ft_strlen(data->data));
	if (data->width > 0 && data->width > data->precision
		&& (data->flag & MINUS) == MINUS)
		ft_minus_width(data, ft_strlen(data->data));
	if (data->width > 0 && data->width > data->precision
		&& (data->flag & MINUS) != MINUS)
		ft_width(data, ft_strlen(data->data));
}
