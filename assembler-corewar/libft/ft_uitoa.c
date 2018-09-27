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

char		*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	len;

	len = ft_digit_lenght((size_t)n, 10);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (str);
}
