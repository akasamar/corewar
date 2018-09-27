/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:00:30 by osapon            #+#    #+#             */
/*   Updated: 2017/11/10 20:23:22 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = (char*)s;
	j = 0;
	while ((tmp[j] == ' ' || tmp[j] == '\n' || tmp[j] == '\t') && tmp[j])
		j++;
	if (!(i = ft_strlen(&tmp[j])))
		return (tmp = ft_strnew(tmp[j]));
	i = ft_strlen(tmp) - 1;
	while (tmp[i] == ' ' || tmp[i] == '\n' || tmp[i] == '\t')
		i--;
	tmp = ft_strsub(tmp + j, 0, i - j + 1);
	return (tmp);
}
