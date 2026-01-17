/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   run_test.c                                              :+:    :+:       */
/*                                                          +:+               */
/*   By: mde-beer <mde-beer@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/16 20:52:29 by mde-beer            #+#    #+#           */
/*   Updated: 2026/01/16 20:53:24 by mde-beer            ########   odam.nl   */
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

#include <ft_printf.h>
#include <framework.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SUPPORTED_SIGNALS 6

const static struct s_map
{
	int			sig;
	t_status	status;
}	g_map[SUPPORTED_SIGNALS] = {
	{SIGSEGV, SEGV},
	{SIGBUS, BUS},
	{SIGABRT, ABRT},
	{SIGFPE, FPE},
	{SIGPIPE, PIPE},
	{SIGILL, ILL}
};

static
t_status	map_signals(int signal)
{
	unsigned int	i;

	i = -1;
	while (++i < SUPPORTED_SIGNALS)
		if (g_map[i].sig == signal)
			return (g_map[i].status);
	return (ERR);
}

static 
void	run_child(t_testfunc func, t_unit_ctx *head)
{
	free_ctx(head);
	exit(func());
}

// TODO: timeout functionality
// probably requires waitpid with WNOHANG + sleep of some sort, i.e.
// philos/codexion
// TODO: captures stdout
// possibly this:
// int	test_printing(void) {
// 	const char	*expected = "expected output\n";
// 	char		*stdout;
// 	int			ret;
//
// 	ret  =run_printer(test_that_prints, &stdout);
// 	if (ret)
// 		return (ret);
// 	return (!!ft_strcmp(stdout, expected));
// }
//
void	run_test(t_test	*test, t_unit_ctx *head)
{
	const pid_t	proc = fork();
	int			stat;

	if (proc == (pid_t)-1)
	{
		test->status = ERR;
		return ;
	}
	if (proc == 0)
		run_child(test->func, head);
	while (wait(&stat) != proc)
		;
	if (WIFEXITED(stat))
	{
		test->status = OK;
		if (WEXITSTATUS(stat))
			test->status = KO;
		return ;
	}
	else if (WIFSIGNALED(stat))
		test->status = map_signals(WTERMSIG(stat));
	else
		test->status = ERR;
}
