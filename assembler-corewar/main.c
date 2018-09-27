/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 21:34:36 by osapon            #+#    #+#             */
/*   Updated: 2018/09/06 22:40:21 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

void		ft_check_last_line(char *file, char *temp)
{
	ssize_t i;
	ssize_t	ret;
	char	buff[80];
	char	*tmp;

	g_fd = open(file, O_RDONLY);
	i = 0;
	while ((ret = read(g_fd, buff, 80)) > 0)
	{
		buff[ret] = '\0';
		i += ret;
		tmp = temp;
		temp = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	if (ret < 0)
		error_print(error_manager_text(6), -42);
	i = ft_strlen(temp);
	if (temp[i - 1] != '\n')
	{
		ft_printf("No NEW LINE at the and of the file\n");
		exit(-1);
	}
	ft_strdel(&temp);
	close(g_fd);
}

void		ft_del_cmd(t_cmd *head)
{
	t_cmd	*temp;

	while (head)
	{
		if (head->name)
			ft_strdel(&head->name);
		if (head->next)
		{
			temp = head->next;
			free(head);
			head = temp;
		}
		else
		{
			free(head);
			head = head->next;
		}
	}
}

void		ft_del_lbl(t_lbl *head)
{
	t_lbl	*temp;

	while (head)
	{
		if (head->name)
			ft_strdel(&head->name);
		if (head->next)
		{
			temp = head->next;
			free(head);
			head = temp;
		}
		else
		{
			free(head);
			head = head->next;
		}
	}
}

void		ft_del_g_s(t_asm *head)
{
	t_asm	*temp;

	while (head)
	{
		if (head->val)
			ft_strdel(&head->val);
		if (head->cmd)
			ft_del_cmd(head->cmd);
		if (head->label)
			ft_del_lbl(head->label);
		if (head->next)
		{
			temp = head->next;
			free(head);
			head = temp;
		}
		else
		{
			free(head);
			head = head->next;
		}
	}
}

int			main(int ac, char **av)
{
	int		i;
	char	*temp;
	t_asm	*im_asm;

	g_flag_nolbl = 0;
	g_flag_op_lbl = 0;
	g_line_numb = 0;
	if (ac > 1)
	{
		i = ac;
		while (i > 1)
		{
			i--;
			temp = av[i];
			ft_check_last_line(av[i], NULL);
			ft_asm(temp, &im_asm);
			ft_del_g_s(im_asm);
		}
	}
	else
		ft_printf("Usage: ./ft_asm [filename].s ...\n");
	return (0);
}
