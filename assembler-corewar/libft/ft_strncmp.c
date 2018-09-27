/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:16:44 by osapon            #+#    #+#             */
/*   Updated: 2017/11/01 18:23:32 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*sec;

	first = (unsigned char*)s1;
	sec = (unsigned char*)s2;
	i = 0;
	while ((i < len) && (first[i] != '\0' || sec[i] != '\0'))
	{
		if (first[i] < sec[i])
			return ((unsigned int)(first[i] - sec[i]));
		if (first[i] > sec[i])
			return ((unsigned int)(first[i] - sec[i]));
		i++;
	}
	return (0);
}
