/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:04:02 by osapon            #+#    #+#             */
/*   Updated: 2017/11/10 20:21:41 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*buff;
	int		j;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	if (!(buff = (char*)malloc(sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		buff[i] = s1[i];
	j = -1;
	while (s2[++j])
		buff[i + j] = s2[j];
	buff[i + j] = '\0';
	return (buff);
}
