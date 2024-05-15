/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 01:46:20 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 19:10:14 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Creates a new string from a specific part of an original string.
RETURN : The new string.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*subst;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
	{
		subst = (char *)malloc(sizeof(char) * 1);
		if (!subst)
			return (NULL);
		subst[0] = '\0';
		return (subst);
	}
	if (len > size - start)
		len = size - start;
	subst = (char *)malloc(sizeof(char) * (len + 1));
	if (!subst)
		return (NULL);
	ft_memcpy(subst, s + start, len);
	subst[len] = '\0';
	return (subst);
}

// int	main(void)
// {
// 	char	*str = "42School42";
// 	printf("%s", ft_substr(str, 8, 2));
// }