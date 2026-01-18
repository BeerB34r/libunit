/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_xlflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslobodi <aslobodi@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:18:07 by aslobodi          #+#    #+#             */
/*   Updated: 2026/01/18 15:23:25 by aslobodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // symbol size_t
#include <framework.h>
#include <libft.h>
#include <limits.h>

// function to be tested:
int	printf(char const *str, ...);

// helper tests
static
int	check_return_one(void)
{
	if (printf("%x", 0x1b2def) == 6)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (printf(" %xx", 0x7fefc3a1) == 10)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
	if (printf("ygs%xxx", UINT_MAX) == 13)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	if (printf("%x%xx%x", 1, 2, -3) == 11)
		return (0);
	return (1);
}

// test function:
int	printf_xlflag_test(void)
{
	int	retval;

	retval = printing_test("1b2def", "", &check_return_one);
	if (!retval)
		retval = printing_test(" 7fefc3a1x", "", &check_return_two);
	if (!retval)
		retval = printing_test("ygsffffffffxx", "", &check_return_three);
	if (!retval)
		retval = printing_test("12xfffffffd", "", &check_return_four);
	if (retval)
		return (retval);
	return (0);
}
