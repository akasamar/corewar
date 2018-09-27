/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:37:19 by osapon            #+#    #+#             */
/*   Updated: 2018/02/24 17:40:21 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*alpha;
	size_t	len;
	int		flag;

	if (value == 0)
		return (ft_strdup("0"));
	flag = (value < 0) ? -1 : 1;
	alpha = "0123456789abcdef";
	len = (value < 0) ? (size_t)(value * flag) : (size_t)value;
	len = ft_digit_lenght(len, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len-- - 1] = alpha[value % base];
		value /= base;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}
