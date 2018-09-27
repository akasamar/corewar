/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:04:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 18:04:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lltoa_base(long long int value, int base)
{
	char	*str;
	char	*alpha;
	size_t	len;

	if (value == 0)
		return (ft_strdup("0"));
	if (value == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	alpha = "0123456789abcdef";
	len = (value < 0) ? (size_t)-value : (size_t)value;
	len = ft_digit_lenght(len, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len)
	{
		str[len-- - 1] = alpha[value % base];
		value /= base;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}
