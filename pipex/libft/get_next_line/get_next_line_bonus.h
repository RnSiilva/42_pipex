/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:18:39 by resilva           #+#    #+#             */
/*   Updated: 2024/03/15 01:52:24 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX 10000

char	*get_next_line(int fd);
int		find_chr(char *str, int c);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	*to_join(char *left_str, char *buff);
char	*ft_read_line(int fd, char *left_str);

#endif