/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:37:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 13:37:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hash(t_option *data, int *i)
{
	char	*str;

	str = data->data;
	data->data = ft_strjoin("0x", str);
	ft_strdel(&str);
	*i += 2;
}

void		ft_width(t_option *data, int i)
{
	char	*sign;

	sign = (data->flag == ZERO) ? ft_strdup("0") : ft_strdup(" ");
	ft_width_extra(data, i, sign);
	ft_strdel(&sign);
}

void		ft_minus_width(t_option *data, int i)
{
	char	*str;

	while (i++ < data->width)
	{
		str = data->data;
		data->data = ft_strjoin(str, " ");
		ft_strdel(&str);
	}
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

void		ft_null_manager(t_option *data)
{
	int		i;

	i = (int)ft_strlen(data->data);
	if ((data->conversion == O_LOWERCASE || data->conversion == O_UPPERCASE)
		&& data->dot && data->precision == 0 && (data->flag & HASH) == HASH)
	{
		ft_strdel(&data->data);
		data->data = ft_strdup("0");
	}
	if (data->conversion == POINTER)
		ft_hash(data, &i);
	if (data->precision > 0 && data->conversion)
		ft_precision(data, (int)ft_strlen(data->data));
	if (data->width > 0 && (data->flag & MINUS) != MINUS)
		ft_width(data, (int)ft_strlen(data->data));
	if (data->width > 0 && (data->flag & MINUS) == MINUS)
		ft_minus_width(data, (int)ft_strlen(data->data));
}
