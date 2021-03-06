/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:37:43 by vnaud             #+#    #+#             */
/*   Updated: 2022/07/01 12:21:07 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTR_H
# define LIBSTR_H

# include <unistd.h>
# include <stdlib.h>
# include "libmem.h"
# include "libchar.h"

int			ft_atoi(const char *nptr);
int			ft_atoi_base(char *str, int base);
long		ft_atol(const char *nptr);
long long	ft_atoll(const char *nptr);
double		ft_atod(const char *nptr);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s, char const *c);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_itoa_base(long long int n, int base);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcnew(size_t size, char c);
char		*ft_strnew(size_t size);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
void		ft_sstrdel(char **array);
char		*ft_strcdup(const char *str, char c);
void		ft_strclear(char *str);
int			ft_strequ(const char *s1, const char *s2);
int			ft_strnequ(const char *s1, const char *s2, size_t len);
char		*ft_strncat(char *dst, const char *src, size_t len);
char		*ft_strndup(const char *src, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strtoupper(char *str);
char		*ft_strtolower(char *str);
char		**ft_sstrdup(char **sstr);

#endif
