/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:54:15 by fshields          #+#    #+#             */
/*   Updated: 2023/12/21 16:55:06 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

//libft
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_int_list
{
	int					value;
	struct s_int_list	*next;
}						t_int_list;

int				ft_atoi(const char *str);
long			ft_atoi_long(const char *str);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *str, int c, size_t n);
char			**ft_split(char const *str, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(char const *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));
t_int_list		*ft_int_lstnew(int value);
void			ft_int_lstadd_back(t_int_list **lst, t_int_list *new);
int				ft_int_lstsize(t_int_list *lst);

//get_next_line
char			*get_next_line(int fd);
int				find_nl_i(char *str);
size_t			gnl_strlen(char *str);
char			*join(char **str, char *buffer, int i);
void			trim_front(char *buffer);
void			ft_bzero(void *str, size_t n);

//ft_printf
int				ft_printf(const char *str, ...);
int				ft_printf_how_long(int n);
int				write_hex(unsigned int n, char type);
int				write_hex_long(unsigned long int n);
int				write_mem_addr(void *ptr);
int				write_int(int n);
int				write_u(unsigned int n);
unsigned int	how_long_u(unsigned int n);
int				how_long_hex(unsigned int n);
int				how_long_hex_long(unsigned long int n);
int				execute_c(va_list *ap);
int				execute_s(va_list *ap);
int				execute_i(va_list *ap);
int				execute_x(va_list *ap, char type);
int				execute_p(va_list *ap);
int				execute_u(va_list *ap);
int				execute_perc(void);

#endif
