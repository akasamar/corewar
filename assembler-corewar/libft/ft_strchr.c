/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:00:28 by osapon            #+#    #+#             */
/*   Updated: 2017/11/02 14:10:41 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*buff;
	size_t	i;

	a = (char)c;
	i = 0;
	buff = (char*)s;
	while (buff[i])
	{
		if (buff[i] == a)
			return (&buff[i]);
		i++;
	}
	return (NULL);
}
