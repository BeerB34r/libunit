/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_sflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslobodi <aslobodi@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:18:37 by aslobodi          #+#    #+#             */
/*   Updated: 2026/01/18 15:38:37 by aslobodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // symbol size_t
#include <framework.h>
#include <libft.h>

// function to be tested:
int	printf(char const *str, ...);

// helper tests
static
int	check_return_one(void)
{
	if (printf(" %s", "random string") == 14)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (printf("%sx", "{} al$#@^&$$^#^@@^$*(") == 22)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
	if (printf("%s%s%s", "this\t", "i\ns", "joined!") == 15)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	if (printf("%ss%ss%ss", "*(1)", "HHHH", "\n\n\n\n") == 15)
		return (0);
	return (1);
}

// test function:
int	printf_sflag_test(void)
{
	int	retval;

	retval = printing_test(" random string", "", &check_return_one);
	if (!retval)
		retval = printing_test("{} al$#@^&$$^#^@@^$*(x", "", &check_return_two);
	if (!retval)
		retval = printing_test("this\ti\nsjoined!", "", &check_return_three);
	if (!retval)
		retval = printing_test("*(1)sHHHHs\n\n\n\ns", "", &check_return_four);
	if (retval)
		return (retval);
	return (0);
}
