/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:47:18 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/24 07:06:27 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void		paint_symb(char **figure, char letter)
{
	char		**y;
	char		*x;

	y = figure;
	while (*y)
	{
		x = y[0];
		while (*x)
		{
			if (*x == '#')
				*x = letter;
			x++;
		}
		y++;
	}
}

static void		read_nuller_begin(t_read *i)
{
	i->lst_chain = NULL;
	i->lst = NULL;
	i->count = 0;
	i->line = NULL;
	i->new_chain = NULL;
}

static void		read_nuller(t_read *i)
{
	i->lst_chain = NULL;
	i->lst = NULL;
	i->count = 0;
}

static void		read_helper(t_read *i)
{
	i->temp = ft_strdup(i->line);
	free(i->line);
	i->lst = ft_lstnew(i->temp, ft_strlen(i->temp));
	ft_lstadd(&(i->lst_chain), i->lst);
	i->count++;
}

t_etra			*reader(int fd)
{
	t_read		i;

	read_nuller_begin(&i);
	while ((i.in = get_next_line(fd, &(i.line))) > 0)
	{
		if (i.line && !ft_strlen(i.line))
		{
			i.lst_chain = ft_lst_turn(i.lst_chain);
			i.new = new_tetra(i.lst_chain);
			i.new_chain = add_tetra(i.new, i.new_chain);
			ft_lst_free_chain(i.lst_chain);
			read_nuller(&i);
		}
		else if (i.line && ft_strlen(i.line))
			read_helper(&i);
	}
	if (i.count)
	{
		i.lst_chain = ft_lst_turn(i.lst_chain);
		i.new = new_tetra(i.lst_chain);
		i.new_chain = add_tetra(i.new, i.new_chain);
	}
	return (i.new_chain);
}
