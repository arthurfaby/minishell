/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:06:26 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:06:23 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static char	**ft_error(char const *s, char c)
{
	char	**res;
	int		index;

	index = -1;
	if (s == NULL)
		return (NULL);
	if (!*s)
	{
		res = malloc(sizeof(char *));
		res[0] = NULL;
		return (res);
	}
	if (c == '\0')
	{
		res = malloc(sizeof(char *) * 2);
		res[0] = malloc(sizeof(char) * ft_strlen(s) + 1);
		while (s[++index])
			res[0][index] = s[index];
		res[0][index] = '\0';
		res[1] = NULL;
		return (res);
	}
	return (NULL);
}

static void	ft_count_word(char const *str, char c, int *word_count)
{
	int	size;

	size = 0;
	while (*(str))
	{
		if (*str == c)
		{
			if (size > 0)
			{
				*word_count += 1;
				size = 0;
			}
		}
		else
			size++;
		str++;
	}
	if (size > 0)
		*word_count += 1;
}

static void	ft_add_word(char **res, char const *str, int *size, int index)
{
	int	intern_index;

	intern_index = *size;
	res[++index] = malloc(sizeof(char) * *size + 1);
	res[index][*size] = '\0';
	while (*size > 0)
	{
		res[index][intern_index - *size] = *(str - *size);
		*size = *size - 1;
	}
}

static void	ft_get_word(char **res, char const *str, char c, int word_count)
{
	int	index;
	int	size;

	size = 0;
	index = -1;
	while (*str && index < word_count)
	{
		if (*str == c)
		{
			if (size > 0)
				ft_add_word(res, str, &size, index++);
		}
		else
			size++;
		str++;
	}
	if (size > 0)
		ft_add_word(res, str, &size, index++);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;

	word_count = 0;
	if (s == NULL || !*s || c == '\0')
		return (ft_error(s, c));
	ft_count_word(s, c, &word_count);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (res == NULL)
		return (NULL);
	ft_get_word(res, s, c, word_count);
	res[word_count] = NULL;
	return (res);
}
