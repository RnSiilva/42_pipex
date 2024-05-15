/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:30:33 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:55:08 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: string.h
DEF: Copies a block of memory from a source to a destination(can overlay data).
RETURN : A pointer to destiny.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "42School";
// 	char	dest[10];
// 	printf("ft_: %s\n", (char *)ft_memcpy(dest, src, 8));
// 	printf("orig: %s\n", (char *)memcpy(dest, src, 8));
// }