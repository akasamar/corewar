/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:25:54 by osapon            #+#    #+#             */
/*   Updated: 2017/11/10 20:15:36 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*buf;

	i = -1;
	if (!s)
		return (NULL);
	if (!(buf = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		buf[i] = f(i, s[i]);
	return (buf);
}
