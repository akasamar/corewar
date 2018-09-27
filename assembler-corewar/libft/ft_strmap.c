/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:18:45 by osapon            #+#    #+#             */
/*   Updated: 2017/11/10 20:15:16 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*buf;

	i = -1;
	if (!s)
		return (NULL);
	if (!(buf = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		buf[i] = f(s[i]);
	return (buf);
}
