/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:21:00 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 18:34:48 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: string.h
DEF: Copies a source string to a destination string, controlling the dest size.
RETURN : Size of the source string.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

// int	main(void)
// {
// 	char	src[] = "42School";
// 	char	dst[] = "4444444444";
// 	unsigned int	size;

// 	size = 9;
// 	printf("\nsrc before: %s\ndest before: %s"
// 	"\nsize before:%d\n\n", src, dst, size);
// 	size = ft_strlcpy(dst, src, size);
// 	printf("src after: %s\ndst after: %s\nsize after:%d\n\n", src, dst, size);
// 	return (0);
// }