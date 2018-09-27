/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:58:45 by osapon            #+#    #+#             */
/*   Updated: 2017/11/10 21:00:22 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s1;
	size_t	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	s1 = (char*)malloc(sizeof(char) * (i + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
