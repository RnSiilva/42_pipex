/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:28:41 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 18:07:06 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Writes a string to a file associated with a 'fd'.
RETURN : None.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// int	main(void)
// {
// 	ft_putstr_fd("42School", 1);
// }