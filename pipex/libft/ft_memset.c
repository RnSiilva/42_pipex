/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:15:38 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 18:01:51 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: string.h
DEF: Fills a block of memory with a specific value from a certain position.
RETURN : A pointer to the start of the memory block after the operation.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str[10];
// 	char	c = '4';
// 	printf("ft_: %s\n", (char *)ft_memset(str, c, 2));
// 	printf("orig: %s\n", (char *)memset(str, c, 2));
// }