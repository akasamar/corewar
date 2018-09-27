/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voiddup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:12:51 by osapon            #+#    #+#             */
/*   Updated: 2017/11/14 11:12:55 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_voiddup(void const *content, size_t content_size)
{
	unsigned char	*cont;
	unsigned char	*stat;
	int				i;

	stat = (unsigned char*)content;
	cont = (unsigned char*)malloc(content_size);
	if (!cont)
		return (NULL);
	i = 0;
	while (content_size)
	{
		cont[i] = stat[i];
		content_size--;
		i++;
	}
	return (cont);
}
