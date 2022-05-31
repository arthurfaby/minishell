/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libchar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:23:27 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 21:26:08 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCHAR_H
# define LIBCHAR_H

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_islower(int c);
int	ft_isprint(int c);
int	ft_ispunct(int c);
int	ft_isgraph(int c);
int	ft_isspace(int c);
int	ft_iswhitespace(int c);
int	ft_isupper(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);

#endif
