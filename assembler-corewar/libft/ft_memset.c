/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:06:54 by osapon            #+#    #+#             */
/*   Updated: 2017/10/31 15:14:43 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int b, size_t len)
{
	size_t			i;
	unsigned char	*new;

	new = (unsigned char*)a;
	i = 0;
	while (i < len)
	{
		new[i] = (unsigned char)b;
		i++;
	}
	return (new);
}
