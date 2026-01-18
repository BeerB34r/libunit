/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslobodi <aslobodi@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:18:12 by aslobodi          #+#    #+#             */
/*   Updated: 2026/01/18 15:30:45 by aslobodi         ###   ########.fr       */
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
	if (printf(" %p", NULL) == 6)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (printf("%p", (void *)-28391422) == 18)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
	if (printf("0x%p-", (void *)ULONG_MAX) == 21)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	if (printf("%pp%p%p", (void *)LONG_MAX + 423856,
			(void *)0, (void *)INT_MAX) == 34)
		return (0);
	return (1);
}

// test function:
int	printf_pflag_test(void)
{
	int	retval;

	retval = printing_test(" (nil)", "", &check_return_one);
	if (!retval)
		retval = printing_test("0xfffffffffe4ec802", "", &check_return_two);
	if (!retval)
		retval = printing_test("0x0xffffffffffffffff-",
				"", &check_return_three);
	if (!retval)
		retval = printing_test("0x80000000000677afp(nil)0x7fffffff",
				"", &check_return_four);
	if (retval)
		return (retval);
	return (0);
}
