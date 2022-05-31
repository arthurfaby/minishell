/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:38:54 by afaby             #+#    #+#             */
/*   Updated: 2022/05/31 15:02:15 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
int	main(void)
{
	char	*res;
	char	*yo;

	while (1)
	{
		ft_printf(">>> ");
		usleep(1);
		yo = get_next_line(0, 1);
		if (strcmp(yo, "exit\n") == 0)
		{
			free(yo);
			break ;
		}
		free(yo);
	}
}
