/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:37:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 13:37:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_int_check(char conversion, char size)
{
	if ((conversion == D_LOWERCASE && size == 0)
		|| (conversion == INTEGER && size == 0)
		|| (conversion == O_LOWERCASE && size == 0)
		|| (conversion == U_LOWERCASE && size == 0)
		|| (conversion == X_LOWERCASE && size == 0)
		|| (conversion == X_UPPERCASE && size == 0))
		return (1);
	else
		return (0);
}

int			ft_long_check(char conversion, char size)
{
	if ((conversion == D_LOWERCASE && size == L)
		|| (conversion == INTEGER && size == L)
		|| (conversion == O_LOWERCASE && size == L)
		|| (conversion == U_LOWERCASE && size == L)
		|| (conversion == X_LOWERCASE && size == L)
		|| (conversion == X_UPPERCASE && size == L)
		|| conversion == D_UPPERCASE
		|| conversion == O_UPPERCASE
		|| conversion == U_UPPERCASE)
		return (1);
	else
		return (0);
}

int			ft_long_long_check(char conversion, char size)
{
	if ((conversion == D_LOWERCASE && size == LL)
		|| (conversion == INTEGER && size == LL)
		|| (conversion == O_LOWERCASE && size == LL)
		|| (conversion == U_LOWERCASE && size == LL)
		|| (conversion == X_LOWERCASE && size == LL)
		|| (conversion == X_UPPERCASE && size == LL)
		|| conversion == POINTER)
		return (1);
	else
		return (0);
}

int			ft_j_check(char conversion, char size)
{
	if ((conversion == D_LOWERCASE && size == J)
		|| (conversion == INTEGER && size == J)
		|| (conversion == O_LOWERCASE && size == J)
		|| (conversion == U_LOWERCASE && size == J)
		|| (conversion == X_LOWERCASE && size == J)
		|| (conversion == X_UPPERCASE && size == J)
		|| conversion == POINTER)
		return (1);
	else
		return (0);
}

int			ft_size_t_check(char conversion, char size)
{
	if ((conversion == D_LOWERCASE && size == Z)
		|| (conversion == INTEGER && size == Z)
		|| (conversion == O_LOWERCASE && size == Z)
		|| (conversion == U_LOWERCASE && size == Z)
		|| (conversion == X_LOWERCASE && size == Z)
		|| (conversion == X_UPPERCASE && size == Z))
		return (1);
	else
		return (0);
}
