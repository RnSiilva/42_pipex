/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:52:27 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:17:48 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: ctype.h
DEF: Checks for an ascii character.
RETURN : Positive number if true, and zero if false.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = '~';
// 	if (ft_isascii(c))
// 		printf("The char '%c' is ascii\n", c);
// 	else
// 		printf("The char '%c' is not ascii\n", c);
// }