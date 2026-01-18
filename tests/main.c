/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   main.c                                                  :+:    :+:       */
/*                                                          +:+               */
/*   By: mde-beer <mde-beer@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/17 12:54:29 by mde-beer            #+#    #+#           */
/*   Updated: 2026/01/17 12:56:43 by mde-beer            ########   odam.nl   */
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
#include <unistd.h>

int	strlen_launcher(void);
int	puts_launcher(void);
int	fib_launcher(void);

const static char *const	g_usage_string
	= CYAN "[USAGE]" CLEAR ": %s [options] [test suite]\n"
	"options:\n"
	"	--test={test suite}\n"
	"	-t {test suite}\n"
	"		specify what test suite to run\n"
	"	--help\n"
	"	-h\n"
	"		print this help information\n"
	"	--list\n"
	"	-l\n"
	"		lists all test suites\n"
	"\n";

#define NO_TEST_ERR " Specified test suite %s doesn't exist\n"
#define NO_FLAG_ERR " Flag %s not recognised\n"
#define NO_ARG_ERR " Missing argument for -t flag\n"

static
void	run_single(char *target, t_unit_ctx **tests)
{
	t_unit_ctx	*current;
	t_unit_ctx	*test;

	current = (*tests)->next;
	test = NULL;
	while (current)
	{
		if (!ft_strncmp(target, current->test.name, ft_strlen(target) + 1))
			test = current;
		current = current->next;
	}
	if (!test)
	{
		free_ctx(*tests);
		ft_dprintf(STDERR_FILENO, RED "[ERROR]" CLEAR NO_TEST_ERR, target);
		exit(1);
	}
	current = (*tests)->next;
	while (current)
	{
		current->test.ignore = true;
		if (test == current)
			current->test.ignore = false;
		current = current->next;
	}
}

static
int	list(t_unit_ctx *current)
{
	current = current->next;
	ft_printf(CYAN "[INFO]" CLEAR " Available test suites:\n");
	while (current)
	{
		ft_printf("	%s\n", current->test.name);
		current = current->next;
	}
	return (1);
}

static
int	flags(int ac, char **av, t_unit_ctx **tests)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strncmp("-t", av[i], ft_strlen("-t") + 1) && i < ac - 1)
			run_single(av[++i], tests);
		else if (!ft_strncmp("-t", av[i], ft_strlen("-t") + 1))
			return (1 + !!ft_dprintf(STDERR_FILENO, RED "[ERROR]" CLEAR
					NO_ARG_ERR));
		else if (!ft_strncmp("--test=", av[i], ft_strlen("--test=")))
			run_single(av[i] + ft_strlen("--test="), tests);
		else if (!ft_strncmp("-h", av[i], ft_strlen("-h") + 1)
			|| !ft_strncmp("--help", av[i], ft_strlen("--help") + 1))
			return (!!ft_printf(g_usage_string, av[0]));
		else if (!ft_strncmp("-l", av[i], ft_strlen("-l") + 1)
			|| !ft_strncmp("--list", av[i], ft_strlen("--list") + 1))
			return (list(*tests));
		else if (av[i][0] == '-')
			return (1 + !!ft_dprintf(STDERR_FILENO, RED "[ERROR]"
					CLEAR NO_FLAG_ERR, av[i]));
		else if (i == ac - 1)
			run_single(av[i], tests);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_unit_ctx	*tests;
	int			flags_ret;

	(void)ac;
	(void)av;
	tests = create_ctx("Tests");
	load_test(&tests,
		(t_test){.name = "strlen tests", .func = &strlen_launcher});
	load_test(&tests,
		(t_test){.name = "puts tests", .func = &puts_launcher});
	load_test(&tests,
		(t_test){.name = "fib tests", .func = &fib_launcher});
	if (!tests)
	{
		free_ctx(tests);
		ft_dprintf(STDERR_FILENO, RED "[FATAL]" CLEAR "%s\n",
			"failed to allocate context");
		return (1);
	}
	if (ac != 1)
	{
		flags_ret = flags(ac, av, &tests);
		if (flags_ret)
		{
			free_ctx(tests);
			return (flags_ret - 1);
		}
	}
	return (launch_tests(&tests));
}
