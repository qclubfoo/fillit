/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_prove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 05:50:11 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/25 21:46:48 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	str_links_prove(t_list *lst, size_t x)
{
	char	*str;

	str = (char *)lst->content;
	if (str[x] == '#')
		return (1);
	return (0);
}

static int	links_prove_helper(t_list *lst, size_t x, size_t y)
{
	size_t	count;

	count = 0;
	if (y)
		count += str_links_prove(ft_lstsearch_index(lst, (y - 1)), x);
	if (y != 3)
		count += str_links_prove(ft_lstsearch_index(lst, (y + 1)), x);
	if (x)
		count += str_links_prove(ft_lstsearch_index(lst, y), (x - 1));
	if (x != 3)
		count += str_links_prove(ft_lstsearch_index(lst, y), (x + 1));
	return (count);
}

int			links_prove(t_list *lst)
{
	size_t	x;
	size_t	y;
	t_list	*temp;
	size_t	links;

	y = 0;
	temp = lst;
	links = 0;
	while (y != 4)
	{
		x = 0;
		while (x != 4)
		{
			if (((char *)(temp->content))[x] == '#')
			{
				if (!(links += links_prove_helper(lst, x, y)))
					return (0);
			}
			x++;
		}
		y++;
		temp = temp->next;
	}
	return (ft_return(links));
}

int			ft_return(size_t links)
{
	if (links > 5)
		return (1);
	else
		return (0);
}
