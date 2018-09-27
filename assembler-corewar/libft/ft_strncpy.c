/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:21:50 by osapon            #+#    #+#             */
/*   Updated: 2017/10/31 17:21:51 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (len > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len)
	{
		dst[i++] = '\0';
		len--;
	}
	return (dst);
}
