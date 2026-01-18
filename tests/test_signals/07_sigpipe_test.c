/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_sigpipe_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:59:24 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 13:33:52 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_signals.h"

static void	close_pipe(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
}

static void	execute_child(int pipefd[2])
{
	close(pipefd[0]);
	write(pipefd[1], "\n", 1);
	close(pipefd[1]);
	exit(EXIT_SUCCESS);
}

int	sigpipe_test(void)
{
	int	pipefd[2];
	int	pid;
	int	status;

	if (pipe(pipefd))
	{
		perror("pipe() error");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		close_pipe(pipefd);
		perror("fork() error");
		return (EXIT_FAILURE);
	}
	if (pid > 0)
		close_pipe(pipefd);
	if (pid == 0)
		execute_child(pipefd);
	if (MAGIC_NUMBER)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
