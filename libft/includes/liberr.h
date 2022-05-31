/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:05:26 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 17:45:41 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBERR_H
# define LIBERR_H

# include "libft.h"
# include "libprint.h"

void	ft_usage_err(char *name, char *params);
void	ft_exit_msg(char *message, int fd);

#endif
