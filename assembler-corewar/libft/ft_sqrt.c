/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:23:08 by osapon            #+#    #+#             */
/*   Updated: 2017/11/14 11:23:10 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int	sroot;

	if (nb < 0)
		return (0);
	sroot = 0;
	while (sroot != nb)
	{
		if (sroot * sroot == nb)
			return (sroot);
		sroot++;
	}
	return (0);
}
