/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:45:21 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 18:18:56 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: string.h
DEF: Creates a duplicate copy of a string(with allocated memory).
RETURN : A pointer to the new duplicated string.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*np;

	np = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!np)
		return (NULL);
	i = 0;
	while (s[i])
	{
		np[i] = s[i];
		i++;
	}
	np[i] = '\0';
	return (np);
}

// int	main(void)
// {
// 	char	*str = "42School";
// 	char	*str2;

// 	str2 = ft_strdup(str);
// 	printf("\n%s\n\n", str2);
// 	free(str2);
// 	return (0);
// }