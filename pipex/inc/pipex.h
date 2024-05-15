/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:58:43 by resilva           #+#    #+#             */
/*   Updated: 2024/05/16 00:33:48 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

//void	error_msg(char *head, char *msg);
void	check_envp(char **envp);
void	free_split(char **arg);
//void	exit_error(void);

//void exit_msg(char *msg);
void error_msg(char *header, char *msg);
