/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:55:05 by vnaud             #+#    #+#             */
/*   Updated: 2022/07/04 10:55:06 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: free_before
* ------------------------- 
*
*	free every element in void ** array before index
*
* Params:
*	void	**args	: array to free
*	int		size	: index last element
*
* Returns:
*	char **(NULL)	: NULL
*
* -------------------------
*/
char	**free_before(void **args, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(args[size]);
		args[size] = NULL;
		i++;
	}
	free(args);
	args = NULL;
	return (NULL);
}

/*
* -------------------------
* Function: free_trio
* ------------------------- 
*
*	free data in char ** array
*
* Params:
*	char **split	: result of ft_split function
*	char **args		: args split
*	char **redirect	: redirections split
*
* Returns:
*
*
* -------------------------
*/
void	free_trio(char **split, char **args, char **redirect)
{
	ft_sstrdel(split);
	ft_sstrdel(args);
	ft_sstrdel(redirect);
}
