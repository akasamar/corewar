/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xbig_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:38:00 by osapon            #+#    #+#             */
/*   Updated: 2018/03/03 23:38:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hash(t_option *data)
{
	char	*str;

	str = data->data;
	data->data = ft_strjoin("0X", str);
	ft_strdel(&str);
}

static void	ft_minus_width(t_option *data, int i)
{
	char	*str;

	if ((data->flag & HASH) == HASH && data->data[1] != 'X')
	{
		ft_hash(data);
		i += 2;
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

	if ((data->flag & HASH) == HASH && data->data[1] != 'X')
	{
		ft_hash(data);
		i += 2;
	}
	sign = ((data->flag & ZERO) == ZERO) ? ft_strdup("0") : ft_strdup(" ");
	ft_width_extra(data, i, sign);
	ft_strdel(&sign);
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
	if ((data->flag & HASH) == HASH)
		ft_hash(data);
}

void		ft_xbig_manager(t_option *data)
{
	int		i;

	i = -1;
	while (data->data[++i])
		data->data[i] = (char)ft_toupper(data->data[i]);
	if ((data->flag & HASH) == HASH && data->data && data->data[0] != '0'
		&& data->precision == 0 && data->width == 0)
		ft_hash(data);
	if (data->precision > 0)
		ft_precision(data, i);
	if (data->width > 0 && data->width > data->precision
		&& (data->flag & MINUS) == MINUS)
		ft_minus_width(data, i);
	if (data->width > 0 && data->width > data->precision
		&& (data->flag & MINUS) != MINUS)
		ft_width(data, (int)ft_strlen(data->data));
}
