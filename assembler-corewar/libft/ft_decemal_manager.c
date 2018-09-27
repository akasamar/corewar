/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decemal_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:11:00 by osapon            #+#    #+#             */
/*   Updated: 2018/03/03 22:11:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width(t_option *d, char **t, int i)
{
	char	*sign;

	sign = ((d->flag & ZERO) == ZERO
			&& d->precision != i) ? ft_strdup("0") : ft_strdup(" ");
	if ((d->flag & ZERO) == ZERO)
		d->data[0] = (char)(((*t)[0] == '-') ? '0' : d->data[0]);
	if ((d->flag & PLUS) == PLUS && (d->flag & ZERO) != ZERO
		&& (*t)[0] != '-' && d->data[0] != '+')
	{
		d->data = ft_strjoin("+", d->data);
		i = ((*t)[0] != '-') ? i + 1 : i;
	}
	ft_width_extra(d, i, sign);
	d->data[0] = (char)((d->flag == ZERO && d->width > d->precision
	&& d->width > (int)ft_strlen(*t) && (*t)[0] != '0') ? ' ' : d->data[0]);
	if ((d->flag & PLUS) != PLUS && (d->flag & ZERO) == ZERO && (*t)[0] != '0')
		d->data[0] = (char)(((*t)[0] == '-') ? '-' : d->data[0]);
	if ((d->flag & PLUS) == PLUS && (d->flag & ZERO) == ZERO && d->width > i)
		d->data[0] = (char)(((*t)[0] == '-') ? '-' : '+');
	if ((d->flag & PLUS) == PLUS && d->width <= i)
		d->data = ft_strjoin("+", d->data);
	d->data[0] = (char)(((d->flag & ZERO) == ZERO && (d->flag & SPACE) == SPACE
						&& d->width > (int)ft_strlen(*t)) ? ' ' : d->data[0]);
	ft_strdel(&sign);
}

static void	ft_minus_width(t_option *data, int i)
{
	char	*str;

	if ((data->flag & SPACE) == SPACE && data->data[0] != '-')
	{
		data->data = ft_strjoin(" ", data->data);
		i += 1;
	}
	while (i++ < data->width)
	{
		str = data->data;
		data->data = ft_strjoin(str, " ");
		ft_strdel(&str);
	}
}

static void	ft_precision(t_option *data, char **tmp, int i)
{
	char	*str;

	i = (data->data[0] == '-') ? i - 1 : i;
	data->data[0] = (char)((*tmp[0] == '-') ? '0' : data->data[0]);
	i = (i < 0) ? 0 : i;
	while (i++ < data->precision)
	{
		str = data->data;
		data->data = ft_strjoin("0", str);
		ft_strdel(&str);
	}
	if ((data->flag & SPACE) == SPACE && (data->flag & PLUS) != PLUS)
		data->data = ft_strjoin(" ", data->data);
	if ((data->flag & SPACE) == SPACE && (data->flag & PLUS) == PLUS)
		data->data = ft_strjoin("+", data->data);
	if ((data->flag & PLUS) == PLUS && data->data[0] != '+')
		data->data = ft_strjoin("+", data->data);
	if ((*tmp)[0] == '-')
		data->data[0] = (char)((*tmp[0] == '-') ? '-' : data->data[0]);
}

static void	ft_exeption(t_option *data, char **tmp, int i)
{
	char	*str;
	char	*sign;

	if (data->precision != 0 && data->flag == ZERO)
		sign = (data->flag == ZERO) ? ft_strdup(" ") : ft_strdup("0");
	else
		sign = (data->flag == ZERO) ? ft_strdup("0") : ft_strdup(" ");
	if ((*tmp)[0] == '-')
		data->data[0] = (char)(((*tmp)[0] == '-') ? '0' : (*tmp)[0]);
	while (i++ < data->width)
	{
		str = data->data;
		data->data = ft_strjoin(sign, str);
		ft_strdel(&str);
	}
	data->data[0] = (char)(((*tmp)[0] == '-') ? '-' : data->data[0]);
	data->data[0] = (char)(((*tmp)[0] == '0') ? ' ' : data->data[0]);
	ft_strdel(&sign);
}

void		ft_decemal_manager(t_option *data)
{
	char	*tmp;

	tmp = ft_strdup(data->data);
	if (data->precision > 0)
		ft_precision(data, &tmp, (int)ft_strlen(data->data));
	if (data->width > 0 && (data->flag & MINUS) != MINUS)
		ft_width(data, &tmp, (int)ft_strlen(data->data));
	if (data->width > 0 && (data->flag & ZERO) == ZERO && data->precision != 0)
		ft_exeption(data, &tmp, (int)ft_strlen(data->data));
	if (data->width > 0 && (data->flag & MINUS) == MINUS)
		ft_minus_width(data, (int)ft_strlen(data->data));
	if (data->flag == SPACE && data->width == 0 && data->precision == 0
		&& data->data[0] != '-')
		data->data = ft_strjoin(" ", data->data);
	if ((data->flag & PLUS) == PLUS && data->width == 0 && data->precision == 0
		&& data->data[0] != '-')
		data->data = ft_strjoin("+", data->data);
	if (data->flag == ZERO && data->precision == 0 && tmp[0] != '-'
		&& tmp[0] != '0' && (int)ft_strlen(tmp) < data->width)
		data->data[0] = '0';
	ft_strdel(&tmp);
}
