/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:36:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 19:36:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulltoa(unsigned long long int n)
{
	char	*str;
	size_t	len;

	len = ft_digit_lenght((size_t)n, 10);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len-- - 1] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (str);
}
