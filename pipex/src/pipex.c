/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:58:59 by resilva           #+#    #+#             */
/*   Updated: 2024/05/16 00:35:07 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*get_path(char *cmd_only, char **envp)
{
	char	**paths;
	char	*only_path;
	char	*cmd_path;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		only_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(only_path, cmd_only);
		free(only_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_split(paths);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_split(paths);
	error_msg(cmd_only, "command not found");
	//error_msg(cmd_only, "command not found");
	return (NULL);
}

void	run_cmd(char **cmd_flags, char **envp)
{
	char	*cmd_path;

	cmd_path = get_path(cmd_flags[0], envp);
	if (!cmd_path)
	{
		free_split(cmd_flags);
		free (cmd_path);
		exit(127);
	}
	if (execve(cmd_path, cmd_flags, envp) == -1)
	{
		free_split(cmd_flags);
		free(cmd_path);
		error_msg(NULL, "execve()");
		//exit_error();
	}
}

// void	run_cmd(char *cmd_only, char **cmd_flags, char **envp)
// {
// 	char	**paths;
// 	int		i;
// 	int		j;

// 	i = -1;
// 	while (envp[++i])
// 	{
// 		if (ft_strnstr(envp[i], "PATH=", 5))
// 		{
// 			paths = ft_split(envp[i] + 5, ':');
// 			j = -1;
// 			while (paths[++j])
// 			{
// 				paths[j] = ft_strjoin(ft_strjoin(paths[j], "/"), cmd_only);
// 				if (access(paths[j], F_OK) == 0)
// 				{
// 					//free_split(paths);
// 					execve(paths[j], cmd_flags, envp);
// 				}
// 			}
// 		}
// 	}
// 	free_split(paths);
// 	free_split(cmd_flags);
// 	ft_printf("command not found\n", cmd_only);
// 	exit(127);
// }

void	parent_process(int *fd, char **av, char **envp)
{
	int		fd_out;
	char	**cmd;

	fd_out = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd_out == -1)
		error_msg(NULL, "open()");
	//	exit_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[1]);
	cmd = ft_split(av[3], ' ');
	run_cmd(cmd, envp);
}

void	child_process(int *fd, char **av, char **envp)
{
	int		fd_in;
	char	**cmd;

	fd_in = open(av[1], O_RDONLY, 0777);
	if (fd_in == -1)
		error_msg(NULL, "open()");
		//exit_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd[0]);
	cmd = ft_split(av[2], ' ');
	run_cmd(cmd, envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		check_envp(envp);
		if (pipe(fd) == -1)
			error_msg(NULL, "pipe()");
			//exit_error();
		pid = fork();
		if (pid == -1)
			error_msg(NULL, "fork()");
			//exit_error();
		if (pid == 0)
			child_process(fd, av, envp);
		waitpid(pid, NULL, 0);
		parent_process(fd, av, envp);
	}
	else
	{
		error_msg("Usage", "./pipex <infile> <cmd1> <cmd2> <outfile>");
		exit(1);
	}
}
