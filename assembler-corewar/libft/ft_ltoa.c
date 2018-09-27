/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:14:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 18:14:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_ltoa(long int n)
{
	char				*str;
	int					flag;
	unsigned long int	i;
	size_t				len;

	flag = (n < 0) ? -1 : 1;
	len = ft_digit_lenght(((size_t)(n * flag)), 10);
	len += (flag < 0) ? 1 : 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = (unsigned long int)(n * flag);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (char)(i % 10 + '0');
		i /= 10;
	}
	if (flag == -1)
		str[0] = '-';
	return (str);
}
