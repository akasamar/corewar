/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:51:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 19:51:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulltoa_base(unsigned long long int value, int base)
{
	char	*str;
	char	*alpha;
	size_t	len;

	if (value == 0)
		return (ft_strdup("0"));
	alpha = "0123456789abcdef";
	len = ft_digit_lenght(value, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len-- - 1] = alpha[value % base];
		value /= base;
	}
	return (str);
}
