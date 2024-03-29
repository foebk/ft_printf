/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:35:00 by ction             #+#    #+#             */
/*   Updated: 2019/04/13 16:25:52 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *str);
void				ft_bzero(void *dest, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *dest, int c, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *str, int ch);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dest, char *src, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strchr(const char *str, int ch);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strrchr(const char *str, int ch);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(unsigned long long n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2, int freeflag);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strndup(const char *src, size_t n);

typedef struct		s_list
{
	char			*content;
	int				content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, int content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_expmem(char *src, size_t mem);
int					ft_str_is_printable(char *c);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_abs(int num);
int					ft_strnchr(const char *str, int ch);
char				*ft_strbs(char *str, char ch);
char				*ft_strfs(char *str, char ch);
void				ft_pushfront(t_list *lst, t_list **head);
char				*ft_itoa_base(unsigned long long value, int base);
long long int		ft_power(int a, int b);
unsigned long long	ft_btoi(char *str);
double				ft_powerneg(double a, int b);

#endif
