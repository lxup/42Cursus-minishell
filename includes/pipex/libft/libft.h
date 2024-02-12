/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:35:41 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/10 04:19:28 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define HEXBASE_MIN "0123456789abcdef"
# define HEXBASE_MAJ "0123456789ABCDEF"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	int					content;
	struct s_list		*next;
	int					index;
}						t_list;

typedef struct s_list_gnl
{
	char				*content;
	struct s_list_gnl	*next;
}						t_list_gnl;

char					*recup_gnl(int fd);
char					*get_next_line(int fd, int moha);
void					ft_lstadd_back_gnl(t_list_gnl *head, char *content);
t_list_gnl				*ft_lstnew_gnl(char *content);
t_list_gnl				*ft_lstlast_gnl(t_list_gnl *lst);
int						get_size(t_list_gnl *head);

int						ft_printf(int fd, const char *str, ...);
size_t					ft_strlen(const char *str);
void					ft_putstr(char const *s, int fd, int *cnt);
void					ft_putchar(char c, int fd, int *cnt);
void					print_arg(char c, va_list args, int *cnt, long *j);
void					ft_putnbr_hex(long unsigned int nbr, char *base,
							int *cnt, int fd);
void					ft_putnbr(int nbr, int *cnt, int fd);
void					ft_putnbr_u(unsigned int nbr, int *cnt, int fd);

int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);

char					*ft_itoa(int n);
int						ft_atoi(const char *str);
int						ft_tolower(int c);
int						ft_toupper(int c);

void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t count, size_t size);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memset(void *b, int c, size_t len);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);

size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t					ft_strlen(const char *str);
char					*ft_strchr(char const *s, int c);
char					*ft_strrchr(char const *s, int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strnstr(char const *haystack, char const *needle,
							size_t len);
char					*ft_strtrim(char const *s, char const *set);
char					*ft_strdup(const char *s1);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					**ft_split(char const *s, char c);
void					free_tab(char **tab);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));

void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char const *s, int fd);

// bonus part

t_list					*ft_lstmap(t_list *lst, int (*f)(int),
							void (*del)(int));
void					ft_lstiter(t_list *lst, void (*f)(int));
void					ft_lstclear(t_list **lst, void (*del)(int));
void					ft_lstdelone(t_list *lst, void (*del)(int));
void					ft_lstadd_back(t_list **lst, t_list *new);
t_list					*ft_lstlast(t_list *lst);
int						ft_lstsize(t_list *lst);
void					ft_lstadd_front(t_list **head, t_list *new);
t_list					*ft_lstnew(int content);

#endif