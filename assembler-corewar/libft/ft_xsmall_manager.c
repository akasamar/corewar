/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsmall_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:21:00 by osapon            #+#    #+#             */
/*   Updated: 2018/03/03 23:21:00 by osapon           ###   ########.fr       */
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

static void	ft_minus_width(t_option *data, int i)
{
	char	*str;

	if ((data->flag & HASH) == HASH && data->data[1] != 'x')
		ft_hash(data, &i);
	if (data->conversion == POINTER)
		ft_hash(data, &i);
	while (i++ < data->width)
	{
		str = data->data;
		data->data = ft_strjoin(str, " ");
		ft_strdel(&str);
	}
}

static void	ft_width(t_option *data, int i)
{
	char	*tmp;
	char	*sign;

	sign = ((data->flag & ZERO) == ZERO) ? ft_strdup("0") : ft_strdup(" ");
	i += ((data->flag & ZERO) == ZERO && data->conversion == POINTER
			&& (data->flag & HASH) != HASH) ? 2 : 0;
	if ((data->flag & HASH) == HASH && data->data[1] != 'x'
		&& (data->flag & ZERO) != ZERO)
		ft_hash(data, &i);
	ft_width_extra(data, i, sign);
	tmp = ft_strdup(data->data);
	data->data[1] = (data->conversion == POINTER) ? data->data[1] : tmp[1];
	data->data[1] = ((data->flag & HASH) == HASH && data->conversion != POINTER
					&& (data->flag & ZERO) != ZERO) ? tmp[1] : data->data[1];
	if (data->conversion == POINTER && !ft_strchr(data->data, 'x'))
		ft_hash(data, &i);
	ft_strdel(&tmp);
	if (data->conversion != POINTER && (data->flag & HASH) == HASH
		&& (data->flag & ZERO) == ZERO && data->data[1] != 'x')
		data->data[1] = 'x';
	ft_strdel(&sign);
}

static void	ft_precision(t_option *data, int i)
{
	char	*str;
	int		j;

	j = 1;
	while (i++ < data->precision)
	{
		str = data->data;
		data->data = ft_strjoin("0", str);
		ft_strdel(&str);
	}
	if ((data->flag & HASH) == HASH && data->conversion != POINTER)
		ft_hash(data, &j);
}

void		ft_xsmall_manager(t_option *data)
{
	int		i;

	i = (int)ft_strlen(data->data);
	if ((data->flag & HASH) == HASH && data->dot != '.'
		&& data->precision == 0 && data->width == 0 && data->data[0] != '0')
		ft_hash(data, &i);
	if (data->precision > 0)
		ft_precision(data, i);
	if (data->conversion == POINTER && !(data->flag))
		ft_hash(data, &i);
	if (data->width > 0 && data->width > data->precision
		&& (data->flag & MINUS) == MINUS)
		ft_minus_width(data, i);
	if (data->width > 0 && data->width > data->precision
		&& (data->flag & MINUS) != MINUS)
		ft_width(data, (int)ft_strlen(data->data));
	if (data->conversion == POINTER
		&& ((data->flag & SPACE) == SPACE || (data->flag & PLUS) == PLUS))
		ft_hash(data, &i);
}
