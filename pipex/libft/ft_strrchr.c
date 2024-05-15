/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:43:47 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 19:00:18 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: string.h
DEF: Search for the last occurrence of specific character in a string.
RETURN : Pointer to the last ocurrence of the character in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (ptr);
}

// int	main(void)
// {
// 	char	*str = "42School42";
// 	printf("%s", ft_strrchr(str, '4'));
// 	return (0);
// }