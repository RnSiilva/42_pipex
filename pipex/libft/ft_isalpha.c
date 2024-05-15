/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:18:52 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:16:47 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: ctype.h
DEF: Checks for an alphabetic character.
RETURN : Positive number if true, and zero if false.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'R';
// 	if (ft_isalpha(c))
// 		printf("The char '%c' is alphabetic\n", c);
// 	else
// 		printf("The char '%c' is not alphabetic\n", c);
// }