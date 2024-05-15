/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:54:06 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:19:51 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: ctype.h
DEF: Checks for any printable character, including space.
RETURN : Positive number if true, and zero if false.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = ' ';
// 	if (ft_isprint(c))
// 		printf("The char '%c' is printable\n", c);
// 	else
// 		printf("The char '%c' is not printable\n", c);
// }