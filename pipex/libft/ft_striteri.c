/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:09:12 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 18:20:50 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Applies a custom function to each character in a string.
RETURN : None.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void ft_change (unsigned int i, char *c)
// {
// 	*c = *c - i;
// }

// int	main(void)
// {
// 	char	str[] = "43Ufltus";
// 	printf("\nOld string: %s\n", str);
// 	ft_striteri(str, ft_change);
// 	printf("New string: %s\n\n", str);
// 	return (0);
// }