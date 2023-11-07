/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:41:38 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/07 11:47:33 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_list t_list;
typedef struct s_btree t_btree;

typedef struct s_list
{
	void			*content;
	t_list			*next;
}					t_list;

typedef struct s_btree
{
	void			*item;
	t_btree			*left;
	t_btree			*right;
}					t_btree;

// ft_array
void		ft_rev_int_tab(int *tab, int size);
void		ft_sort_int_tab(int *tab, int size);
void		ft_print_array(int *array, int size);
void		ft_double_array_free(char **arr);
void		ft_double_array_printer(char **arr);

// ft_ascii_check
void		ft_is_negative(int n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *src, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strreplace(char **pold, const char *new);
char		*ft_strstr(char *str, char *to_find);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *str, const char *find, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *src, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_wsplit(const char *str);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del) (void *));
void		ft_lstclear(t_list **lst, void (*del) (void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_btree		*ft_btree_create_node(void *item);
void		ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void 		ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));
void		ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void 		ft_btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void 		*ft_btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int			ft_btree_level_count(t_btree *root);

// ft_math
void		ft_div_mod(int a, int b, int *div, int *mod);
int			ft_fibonacci(int index);
int			ft_find_next_prime(int nb);
int			ft_is_prime(int nb);
void		ft_ultimate_div_mod(int *a, int *b);
int			ft_recursive_factorial(int nb);
int			ft_recursive_power(int nb, int power);
int			ft_sqrt(int nb);
int			*ft_range(int min, int max);
int			ft_ultimate_range(int **range, int min, int max);
void		ft_swap(int *a, int *b);
int			ft_iterative_factorial(int nb);
int			ft_iterative_power(int nb, int power);


#endif
