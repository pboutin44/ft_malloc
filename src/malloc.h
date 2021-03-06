/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:38:26 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/18 16:51:22 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>
# define PSIZE getpagesize()
# define TRUE '1'
# define FALSE '0'

typedef	char		t_bool;
typedef struct		s_list
{
	size_t			content_size;
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_malloc
{
	t_list			*tiny;
	t_list			*small;
	t_list			*large;
}					t_malloc;

typedef struct		s_norm_reall
{
	char			*addr;
	char			*ptr1;
	char			*ptr;
	int				i;
	size_t			size;

}					t_norm_reall;

t_malloc			g_zone;

void				*malloc(size_t	size);
void				show_alloc_mem();
void				*already_small(size_t size);
void				*first_small(size_t size);
int					one_place_atleastsmall(t_list	*elem);
int					set_smallheader(t_list *lst);
void				ft_putnbr(int n);
void				ft_putstr(const char *str);
char				*ft_addr(void *v);
void				*another_small(size_t size);
void				*already_large(size_t size);
void				*first_large(size_t size);
t_list				*ft_lstiter(t_list	*lst, int (f)(t_list *elem));
void				browse_lst2(t_list	*lst, int off_set, int size);
t_list				*browse_lst(t_list	*lst);
t_list				*ft_lstnew(void const *content, size_t content_size);
int					set_tinyheader(t_list	*lst);
int					one_place_atleasttiny(t_list	*elem);
void				*another_tiny(size_t size);
void				*already_tiny(size_t size);
void				*first_tiny(size_t size);
char				identify_letter(void *ptr);
void				*realloc(void *ptr, size_t size);
void				free(void *ptr);
void				free_tiny(void *ptr);
void				free_small(void *ptr);
int					free_small2(void *ptr, t_list *lst, int y);
int					free2(t_list *lst, t_list *lst3, size_t size);
void				free_tiny1(void *ptr, t_list *lst, int y);
t_list				*find_browsesmall(void *ptr);
t_list				*find_browsesmall2(t_list *lst);
t_list				*find_browsetiny(void *ptr);
t_list				*find_browselarge(void *ptr);

#endif
