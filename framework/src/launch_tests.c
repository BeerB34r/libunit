/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   launch_tests.c                                          :+:    :+:       */
/*                                                          +:+               */
/*   By: mde-beer <mde-beer@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/16 21:27:47 by mde-beer            #+#    #+#           */
/*   Updated: 2026/01/16 21:42:46 by mde-beer            ########   odam.nl   */
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

static
int	test_length(t_unit_ctx *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

static
void	output_test_result(char *function_name, t_test test)
{
	char	*color;

	if (test.status == test.expected)
		color = GREEN;
	else if (test.status == ERR)
		color = MAGENTA;
	else
		color = RED;
	log_test(function_name, test);
	ft_printf("%s:%s:%s%s" CLEAR "\n",
		function_name,
		test.name,
		color,
		status(test.status)
		);
}

static
void	print_final_result(int passing_tests, int total_tests)
{
	const int	percent = passing_tests * 100 / total_tests;

	ft_printf("%i/%i [%3i%%] tests passed\n",
		passing_tests, total_tests, percent);
}

static
void	administer_test(
int *passing_tests,
t_unit_ctx *current,
t_unit_ctx **head
)
{
	run_test(&current->test, *head);
	if (current->test.status == current->test.expected)
		(*passing_tests)++;
	if (!current->test.silent)
		output_test_result((*head)->test.name, current->test);
}

// NB: invalidates context pointer
int	launch_tests(t_unit_ctx **head)
{
	t_unit_ctx	*current;
	int			total_tests;
	int			passing_tests;

	current = *head;
	if (!current)
		return (42);
	current = current->next;
	total_tests = test_length(current);
	passing_tests = 0;
	while (current)
	{
		if (current->test.ignore)
			total_tests--;
		else
			administer_test(&passing_tests, current, head);
		current = current->next;
	}
	print_final_result(passing_tests, total_tests);
	free_ctx(*head);
	return (!(total_tests == passing_tests) * -1);
}
