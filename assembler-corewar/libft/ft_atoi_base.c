/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 19:58:59 by osapon            #+#    #+#             */
/*   Updated: 2018/09/23 16:30:30 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char str)
{
	if (str >= '0' && str <= '9')
		return (str - 48);
	if (str >= 'a' && str <= 'f')
		return (str - 97 + 10);
	if (str >= 'A' && str <= 'F')
		return (str - 65 + 10);
	return (0);
}

long int		ft_atoi_base(char *str, int base)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 0;
	res = 0;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		str++;
		sign = 1;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F'))
		res = res * base + (check(str[i++]));
	return (sign ? -(int)res : (int)res);
}
