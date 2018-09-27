/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:12:15 by osapon            #+#    #+#             */
/*   Updated: 2017/11/02 14:33:34 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*buff;
	char	a;

	a = (char)c;
	buff = (char*)s;
	i = ft_strlen(buff);
	while (0 != i && buff[i] != a)
		i--;
	if (buff[i] == a)
		return (&buff[i]);
	return (NULL);
}
