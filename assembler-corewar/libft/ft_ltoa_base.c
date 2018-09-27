/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:56:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 16:56:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ltoa_base(long int value, int base)
{
	char	*str;
	char	*alpha;
	size_t	len;

	if (value == 0)
		return (ft_strdup("0"));
	if (value == -2147483647)
		return (ft_strdup("-2147483647"));
	value = (value < 0) ? -value : value;
	alpha = "0123456789abcdef";
	len = ft_digit_lenght(value, base);
	str = ft_strnew(len);
	while (len)
	{
		str[len-- - 1] = alpha[value % base];
		value /= base;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}
