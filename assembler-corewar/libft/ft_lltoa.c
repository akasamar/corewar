/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:36:00 by osapon            #+#    #+#             */
/*   Updated: 2018/02/28 19:36:00 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lltoa(long long int n)
{
	char	*str;
	int		flag;
	size_t	len;

	if (n == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	n = (n < 0) ? -n : n;
	flag = (n < 0) ? -1 : 1;
	len = ft_digit_lenght((size_t)n, 10);
	len += (flag < 0) ? 1 : 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len-- - 1] = (char)(n % 10 + '0');
		n /= 10;
	}
	if (flag == -1)
	{
		str[0] = '-';
		if (!ft_strcmp(str, "-'..--).0-*(+,))+(0("))
			return (ft_strdup("-9223372036854775808"));
	}
	return (str);
}
