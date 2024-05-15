/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:32:02 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 22:14:18 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Writes a string followed by a newline to a file associated with a 'fd'.
RETURN : None.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	ft_putendl_fd("42School", 1);
// }