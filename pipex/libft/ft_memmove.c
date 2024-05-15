/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:37:43 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:56:15 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: string.h
DEF: Copies a block of memory from a source to a destination(Does not overlap).
RETURN : A pointer to destiny.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	if (d > s)
	{
		i = n;
		while (--i < n)
			d[i] = s[i];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "World!";
// 	char	dest[20] = "Heelooooo";
// 	printf("\nft_: %s", (char *)ft_memmove(dest, src, 8));

// 	char	src1[] = "World!";
// 	char	dest1[20] = "Heeloooo";
// 	printf("\norig: %s\n\n", (char *)memmove(dest1, src1, 8));

// 	return (0);
// }