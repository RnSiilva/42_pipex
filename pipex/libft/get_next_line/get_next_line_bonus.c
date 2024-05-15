/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:54:12 by resilva           #+#    #+#             */
/*   Updated: 2024/03/15 01:52:49 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *left_str)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!find_chr(left_str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(left_str);
			return (NULL);
		}
		buff[bytes] = '\0';
		left_str = to_join(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX)
		return (NULL);
	left_str[fd] = ft_read_line(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd;
// 	int		fd2;
// 	int		fd3;

// 	fd = open("foo.txt", O_RDONLY);
// 	fd2 = open("foo2.txt", O_RDONLY);
// 	fd3 = open("foo3.txt", O_RDONLY);
// 	i = 0;
// 	while (i++ < 6)
// 	{
// 		line = get_next_line(fd);
// 		printf("[%02d] -> %s", i, line);
// 		line = get_next_line(fd2);
// 		printf("[%02d] -> %s", i, line);
// 		line = get_next_line(fd3);
// 		printf("[%02d] -> %s", i, line);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }