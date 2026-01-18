/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_xuflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslobodi <aslobodi@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:18:02 by aslobodi          #+#    #+#             */
/*   Updated: 2026/01/18 15:23:32 by aslobodi         ###   ########.fr       */
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
	if (printf("%X", 0x1b2def) == 6)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (printf(" %Xx", 0x7fefc3a1) == 10)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
	if (printf("ygs%Xxx", UINT_MAX) == 13)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	if (printf("%X%Xx%X", 1, 2, -3) == 11)
		return (0);
	return (1);
}

// test function:
int	printf_xuflag_test(void)
{
	int	retval;

	retval = printing_test("1B2DEF", "", &check_return_one);
	if (!retval)
		retval = printing_test(" 7FEFC3A1x", "", &check_return_two);
	if (!retval)
		retval = printing_test("ygsFFFFFFFFxx", "", &check_return_three);
	if (!retval)
		retval = printing_test("12xFFFFFFFD", "", &check_return_four);
	if (retval)
		return (retval);
	return (0);
}
