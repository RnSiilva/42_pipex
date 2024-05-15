/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:52:23 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:49:45 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: string.h
DEF: Compares two memory areas, byte by byte.
RETURN : The difference of s1 and s2 (numerically), and zero if they are equal.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int	n;
// 	char	s1[] = "42School";
// 	char	s2[] = "42School";

// 	n = 4;
// 	printf("ft_: %d\n", ft_memcmp(s1, s2, n));
// 	printf("orig: %d\n", memcmp(s1, s2, n));
// 	return (0);
// }