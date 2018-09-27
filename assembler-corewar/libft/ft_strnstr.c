/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:43:51 by osapon            #+#    #+#             */
/*   Updated: 2017/11/02 20:32:05 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;

	if (s2[0] == '\0')
		return ((char*)s1);
	while (*s1 && len)
	{
		i = 0;
		while (*(s1 + i) == s2[i] && len - i)
		{
			i++;
			if (s2[i] == '\0')
				return ((char*)s1);
		}
		s1++;
		len--;
	}
	return (0);
}
