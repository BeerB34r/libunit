/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_iflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslobodi <aslobodi@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:18:26 by aslobodi          #+#    #+#             */
/*   Updated: 2026/01/18 15:54:33 by aslobodi         ###   ########.fr       */
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
	if (printf("%i", 0) == 1)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (printf("%ix%i", -10, 50000) == 9)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
	if (printf("%ii%i%ii%i", 2147483647, 2147483647, 0, 2147483647) == 33)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	int	n;

	n = -2147483648;
	if (printf("%i%ii%i", -10, n, 0) == 16)
		return (0);
	return (1);
}

// test function:
int	printf_iflag_test(void)
{
	int	retval;

	retval = printing_test("0", "", &check_return_one);
	if (!retval)
		retval = printing_test("-10x50000", "", &check_return_two);
	if (!retval)
		retval = printing_test("2147483647i21474836470i2147483647",
				"", &check_return_three);
	if (!retval)
		retval = printing_test("-10-2147483648i0", "", &check_return_four);
	if (retval)
		return (retval);
	return (0);
}
