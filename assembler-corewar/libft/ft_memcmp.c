/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:43:22 by osapon            #+#    #+#             */
/*   Updated: 2017/11/02 15:55:33 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*second;

	first = (unsigned char*)s1;
	second = (unsigned char*)s2;
	i = 0;
	while (i < len)
	{
		if (first[i] > second[i])
			return ((int)(first[i] - second[i]));
		if (first[i] < second[i])
			return ((int)(first[i] - second[i]));
		i++;
	}
	return (0);
}
