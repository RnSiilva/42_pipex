/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:47:28 by resilva           #+#    #+#             */
/*   Updated: 2023/10/18 16:54:13 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Splits a strig into substrings based on a delimiter character.
RETURN : Resulting array of strings.
*/

#include "libft.h"

static void	ft_allocate(char **result, char const *s, char c)
{
	char		**p_ptr;
	char const	*tmp;

	p_ptr = result;
	tmp = s;
	while (*tmp)
	{
		while (*s == c)
			s++;
		tmp = s;
		while (*tmp && *tmp != c)
			tmp++;
		if (*tmp == c || tmp > s)
		{
			*p_ptr = ft_substr(s, 0, tmp - s);
			s = tmp;
			p_ptr++;
		}
	}
	*p_ptr = NULL;
}

static int	ft_count_subs(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_subs(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	ft_allocate(result, s, c);
	return (result);
}

// int     main(void)
// {	
// 	int     i;
// 	char    string[] = "Hello everybody,keep swimming";
// 	char    **result = ft_split(string, ',');

// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }