/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_cflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslobodi <aslobodi@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:18:42 by aslobodi          #+#    #+#             */
/*   Updated: 2026/01/18 15:55:17 by aslobodi         ###   ########.fr       */
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
	if (printf(" %c", 'x') == 2)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (printf("%c%c%c", 'a', ' ', 'b') == 3)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
	if (printf("%cc%cc%c", 'a', ' ', 'b') == 5)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	if (printf("%cs%cs%c", 'a', ' ', 'b') == 5)
		return (0);
	return (1);
}

// test function:
int	printf_cflag_test(void)
{
	int	retval;

	retval = printing_test(" x", "", &check_return_one);
	if (!retval)
		retval = printing_test("a b", "", &check_return_two);
	if (!retval)
		retval = printing_test("ac cb", "", &check_return_three);
	if (!retval)
		retval = printing_test("as sb", "", &check_return_four);
	if (retval)
		return (retval);
	return (0);
}
