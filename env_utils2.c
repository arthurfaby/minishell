#include "minishell.h"

/*
* -------------------------
* Function: create_name
* ------------------------- 
*
*	malloc and fill the name of the new variable
*
* Params:
*	char *str	: input line of the user
*
* Returns:
*	NULL		: malloc error
*	char *name	: name of the variable
*
* -------------------------
*/
char	*create_name(char *str)
{
	int		size;
	char	*name;

	size = 0;
	while (str[size] && str[size] != '=')
		size++;
	name = malloc(sizeof(char) * (size + 1));
	if (!name)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '=')
	{
		name[size] = str[size];
		size++;
	}
	name[size] = '\0';
	return (name);
}

/*
* -------------------------
* Function: create_value
* ------------------------- 
*
*	malloc and fill the value of the new variable
*
* Params:
*	char *str	: input line of the user
*
* Returns:
*	NULL		: malloc error
*	char *value	: value of the variable
*
* -------------------------
*/
char	*create_value(char *str)
{
	int		j;
	int		i;
	char	*value;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		i++;
	j = i;
	while (str[j])
		j++;
	value = malloc(sizeof(char) * (j - i + 1));
	if (!value)
		return (NULL);
	j = i;
	while (str[j])
	{
		value[j - i] = str[j];
		j++;
	}
	value[j - i] = '\0';
	return (value);
}
