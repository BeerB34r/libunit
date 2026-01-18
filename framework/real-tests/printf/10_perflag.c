/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_perflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslobodi <aslobodi@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:17:47 by aslobodi          #+#    #+#             */
/*   Updated: 2026/01/18 15:23:39 by aslobodi         ###   ########.fr       */
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
	if (printf(" %% ") == 3)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (printf(" %%   %%   %% ") == 11)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
	if (printf("%%c ") == 3)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	if (printf(" x %% 21%%c%%") == 10)
		return (0);
	return (1);
}

// test function:
int	printf_perflag_test(void)
{
	int	retval;

	retval = printing_test(" % ", "", &check_return_one);
	if (!retval)
		retval = printing_test(" %   %   % ", "", &check_return_two);
	if (!retval)
		retval = printing_test("%c ", "", &check_return_three);
	if (!retval)
		retval = printing_test(" x % 21%c%", "", &check_return_four);
	if (retval)
		return (retval);
	return (0);
}
