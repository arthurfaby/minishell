/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprint.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:26:34 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 22:49:20 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINT_H
# define LIBPRINT_H

# include <unistd.h>
# include <limits.h>
# include "libmem.h"
# include "libstr.h"

int		ft_putchar_fd(char c, int fd);
int		ft_putchar(char c);
int		ft_putstr_fd(char *s, int fd);
int		ft_putstr(char *s);
int		ft_putnstr_fd(char *s, int n, int fd);
int		ft_putnstr(char *s, int n);
void	ft_putsstr_fd(char **s, int fd);
void	ft_putsstr(char **s);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr(int n);
int		ft_putendl_fd(char *s, int fd);
int		ft_putendl(char *s);
int		ft_putptr(void *ptr);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned int n, char hex);

#endif
