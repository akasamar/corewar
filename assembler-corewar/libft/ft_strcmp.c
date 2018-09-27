/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:53:12 by osapon            #+#    #+#             */
/*   Updated: 2017/10/31 18:53:15 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*sec;

	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	if (s1[i] == '\0')
		return (-1);
	if (s2[i] == '\0')
		return (1);
	first = (unsigned char*)s1;
	sec = (unsigned char*)s2;
	while (first[i] || sec[i])
	{
		if (first[i] < sec[i])
			return ((unsigned int)(first[i] - sec[i]));
		if (first[i] > sec[i])
			return ((unsigned int)(first[i] - sec[i]));
		i++;
	}
	return (0);
}
