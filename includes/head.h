/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:47:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/25 21:42:29 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../Libft/includes/libft.h"

typedef struct			s_tetr
{
	char				**str;
	size_t				height;
	size_t				width;
	char				letter;
	struct s_tetr		*next;
}						t_etra;

typedef struct			s_puter
{
	size_t				x;
	size_t				y;
	size_t				size;
}						t_put;

typedef struct			s_try
{
	char				**figure;
	char				*line;
	size_t				ys;
	size_t				xs;
}						t_try;

typedef struct			s_read
{
	char				*line;
	int					in;
	int					count;
	t_list				*lst;
	t_list				*lst_chain;
	t_etra				*new;
	t_etra				*new_chain;
	char				*temp;
	int					work_indicate;
}						t_read;

int						links_prove(t_list *lst);
int						proves(t_list *chain);
t_etra					*new_tetra(t_list *chain);
t_etra					*reader(int fd);
size_t					new_tetra_number(size_t *s);
t_etra					*create_tetra(size_t x, size_t y);
t_etra					*add_tetra(t_etra *new, t_etra *old);
void					worker(char **map, t_etra	*tets);
char					**new_map(t_etra *tets);
void					out(char **map);
int						t_in(size_t *arr);
int						search_not_dot(char *str);
size_t					len_without_dot(char *str);
void					letters_painter(t_etra *tets);
void					paint_symb(char **figure, char letter);
int						ft_check(int fd, int argc);
int						ft_return(size_t links);

#endif
