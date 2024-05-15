/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:33:58 by resilva           #+#    #+#             */
/*   Updated: 2024/03/15 01:50:00 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: string.h
DEF: Search for the first occurrence of a specific character in a string.
RETURN : A pointer to the fisrt position found.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

// int	main(void)
// {
// 	char	*str = "42School42";
// 	printf("%s", ft_strchr(str, 'S'));
// 	return (0);
// }

// /*char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*(unsigned char *)s == (unsigned char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (*(unsigned char *)s == (unsigned char)c)
// 		return ((char *)s);
// 	return (NULL);
// }*/