/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:01:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/11 12:01:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_long_long_pars(va_list *ap, t_option *data)
{
	if (data->conversion == D_LOWERCASE || data->conversion == INTEGER)
		data->data = ft_lltoa(va_arg(*ap, long long));
	else if (data->conversion == O_LOWERCASE)
		data->data = ft_ulltoa_base(va_arg(*ap, unsigned long long), 8);
	else if (data->conversion == X_UPPERCASE || data->conversion == X_LOWERCASE
			|| data->conversion == POINTER)
		data->data = ft_ulltoa_base(va_arg(*ap, unsigned long long), 16);
	else
		data->data = ft_ulltoa(va_arg(*ap, unsigned long long));
}

void		ft_size_t_pars(va_list *ap, t_option *data)
{
	if (data->conversion == D_LOWERCASE || data->conversion == INTEGER)
		data->data = ft_ulltoa(va_arg(*ap, size_t));
	else if (data->conversion == O_LOWERCASE)
		data->data = ft_ulltoa_base(va_arg(*ap, size_t), 8);
	else if (data->conversion == X_LOWERCASE || data->conversion == X_UPPERCASE)
		data->data = ft_ulltoa_base(va_arg(*ap, size_t), 16);
	else
		data->data = ft_ulltoa_base(va_arg(*ap, size_t), 10);
}

int			ft_char_check(char conversion, char size)
{
	if (conversion == C_LOWERCASE || conversion == S_LOWERCASE
		|| conversion == C_UPPERCASE || conversion == S_UPPERCASE
		|| (conversion == C_LOWERCASE && size == L)
		|| (conversion == S_LOWERCASE && size == L)
		|| (conversion == D_LOWERCASE && size == HH)
		|| (conversion == INTEGER && size == HH)
		|| (conversion == O_LOWERCASE && size == HH)
		|| (conversion == U_LOWERCASE && size == HH)
		|| (conversion == X_LOWERCASE && size == HH)
		|| (conversion == X_UPPERCASE && size == HH))
		return (1);
	else
		return (0);
}

int			ft_short_check(char conversion, char size)
{
	if ((conversion == D_LOWERCASE && size == H)
		|| (conversion == INTEGER && size == H)
		|| (conversion == O_LOWERCASE && size == H)
		|| (conversion == U_LOWERCASE && size == H)
		|| (conversion == X_LOWERCASE && size == H)
		|| (conversion == X_UPPERCASE && size == H))
		return (1);
	else
		return (0);
}
