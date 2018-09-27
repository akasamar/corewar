/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:47:05 by osapon            #+#    #+#             */
/*   Updated: 2017/11/14 11:47:09 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_remove_last(t_list *head)
{
	int		ret;
	t_list	*current;

	ret = 0;
	if (head->next == NULL)
	{
		ret = head->content_size;
		free(head);
		return (ret);
	}
	current = head;
	while (current->next->next != NULL)
		current = current->next;
	ret = current->next->content_size;
	free(current->next);
	current->next = NULL;
	return (ret);
}
