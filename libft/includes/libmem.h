/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:54:52 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/24 08:05:38 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMEM_H
# define LIBMEM_H

# include <unistd.h>
# include <stdlib.h>

typedef unsigned char	t_uchar;

void	ft_bzero(void *s, size_t len);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
void	ft_memdel(void **data);
void	ft_memndel(void **array, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
