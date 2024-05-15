/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:59:42 by resilva           #+#    #+#             */
/*   Updated: 2024/03/15 18:15:55 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *left_str)
{
	char	*str;
	int		i;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
		str = (char *)malloc(sizeof(char) * i + 1);
	else
		str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(left_str) - i);
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*to_join(char *left_str, char *buff)
{
	char	*str;
	int		i;
	int		j;

	if (!left_str)
	{
		left_str = (char *)malloc(sizeof(char) * 1);
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = (char *)malloc(ft_strlen(left_str) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i])
			str[i] = left_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	free(left_str);
	return (str);
}

int	find_chr(char *str, int c)
{
	int	i;

	if (!str || !c)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}
