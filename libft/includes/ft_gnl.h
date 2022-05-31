/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:49:48 by vnaud             #+#    #+#             */
/*   Updated: 2022/05/31 15:10:03 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFFER_SIZE 256

char	*get_next_line(int fd);
char	*ft_strjoins(char *s1, char *s2);
char	*clear_buffer(char *buffer);
char	*read_fd(int fd, char *buffer);
char	*get_line(char *buffer);

#endif
