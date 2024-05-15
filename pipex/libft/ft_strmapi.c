/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:06:48 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 22:14:24 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Applies a custom function to each character in a string, creates a new one.
RETURN : The new modified new.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}

// char	ft_change(unsigned int i, char c)
// {
// 	c = c - 1;
// 	return (c);
// }

// int	main(void)
// {
// 	char	*str = "53Tdippm";
// 	printf("\nOld string: %s\nNew string: %s\n\n", 
// 	str, ft_strmapi(str, ft_change));
// 	return (0);
// }