/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:11:18 by resilva           #+#    #+#             */
/*   Updated: 2024/05/16 18:31:32 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_split(char **arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		free(arg[i]);
	free(arg);
}

void	error_msg(char *header, char *msg)
{
	if (header)
	{
		ft_putstr_fd(header, 2);
		ft_putstr_fd(":", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		perror(msg);
		exit(EXIT_FAILURE);
	}
}

void	check_envp(char **envp)
{
	int	check;
	int	i;

	i = -1;
	check = 0;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH=", 5) && envp[i][6])
			check = 1;
	if (!check)
		error_msg(NULL, "The envitonment PATH has no values");
}
