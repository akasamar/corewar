/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:37:19 by osapon            #+#    #+#             */
/*   Updated: 2017/11/13 23:37:21 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		flag;
	char	*str;
	size_t	len;

	flag = (n < 0) ? -1 : 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n *= flag;
	len = ft_digit_lenght((size_t)n, 10);
	len += (flag < 0) ? 1 : 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (char)(n % 10 + '0');
		n /= 10;
	}
	if (flag == -1)
		str[0] = '-';
	return (str);
}
