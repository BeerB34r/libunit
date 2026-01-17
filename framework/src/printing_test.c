/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   printing_test.c                                         :+:    :+:       */
/*                                                          +:+               */
/*   By: mde-beer <mde-beer@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/17 13:37:25 by mde-beer            #+#    #+#           */
/*   Updated: 2026/01/17 14:05:04 by mde-beer            ########   odam.nl   */
/*                                                                            */
/*   —————No norm compliance?——————                                           */
/*   ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝                                           */
/*   ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇                                           */
/*   ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀                                           */
/*   ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀⠀                                           */
/*   ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ——————————————————————————————                                           */
/* ************************************************************************** */

#include <libft.h>
#include <framework.h>
#include <sys/wait.h>
#include <unistd.h>

static
int	init(int stdoutpipe[2], int stderrpipe[2])
{
	if (pipe(stdoutpipe))
		return (1);
	if (pipe(stderrpipe))
	{
		close(stdoutpipe[0]);
		close(stdoutpipe[1]);
		return (1);
	}
	return (0);
}

static
int	compare_file_to_str(const char *str, const int fd)
{
	char	*file_contents;
	char	*next;
	char	*tmp;
	int		retval;

	file_contents = get_next_line(fd);
	if (!file_contents)
		file_contents = ft_strdup("");
	next = get_next_line(fd);
	while (next)
	{
		tmp = ft_strjoin(file_contents, next);
		free(file_contents);
		free(next);
		if (!tmp)
			return (1);
		file_contents = tmp;
		next = get_next_line(fd);
	}
	retval = ft_strncmp(str, file_contents, ft_strlen(str));
	free(file_contents);
	return (retval);
}

static
void	wait_for_child(pid_t proc, t_test *test)
{
	int	stat;

	while (wait(&stat) != proc)
		;
	if (WIFEXITED(stat))
	{
		test->status = OK;
		if (WEXITSTATUS(stat))
			test->status = KO;
	}
	else if (WIFSIGNALED(stat))
		test->status = map_signal_status(WTERMSIG(stat));
	else
		test->status = ERR;
}

static
void	run_printing_test(t_test *test, int stdoutpipe[2], int stderrpipe[2])
{
	const pid_t	proc = fork();

	if (proc == (pid_t)-1)
	{
		close(stdoutpipe[1]);
		close(stderrpipe[1]);
		test->status = ERR;
		return ;
	}
	if (proc == 0)
	{
		close(stdoutpipe[0]);
		close(stderrpipe[0]);
		dup2(stdoutpipe[1], STDOUT_FILENO);
		dup2(stderrpipe[1], STDERR_FILENO);
		exit(!test->func());
	}
	close(stdoutpipe[1]);
	close(stderrpipe[1]);
	wait_for_child(proc, test);
}

int	printing_test(char *expected_stdout, char *expected_stderr, t_testfunc func)
{
	int		stdoutpipe[2];
	int		stderrpipe[2];
	int		retval;
	t_test	test;

	if (init(stdoutpipe, stderrpipe))
		return (1);
	test.func = func;
	test.status = UNKNOWN;
	run_printing_test(&test, stdoutpipe, stderrpipe);
	if (test.status != OK)
	{
		close(stdoutpipe[0]);
		close(stderrpipe[0]);
		return (map_status_retval(test.status));
	}
	retval = !!compare_file_to_str(expected_stdout, stdoutpipe[0]);
	if (!retval)
		retval = !!compare_file_to_str(expected_stderr, stderrpipe[0]);
	close(stdoutpipe[0]);
	close(stderrpipe[0]);
	return (retval);
}
