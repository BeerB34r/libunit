/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_mixed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslobodi <aslobodi@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:08:37 by aslobodi          #+#    #+#             */
/*   Updated: 2026/01/18 15:22:56 by aslobodi         ###   ########.fr       */
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
	if (printf("%%%c%%%s%%%d%%%i%u%%%x%%%X%%%% "
			"%%%c%%%s%%%d%i%%%u%%%x%%%X%%%% %%%c%s%%%d"
			"%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 21, 42, 42,
			21, 42, 'B', "-42", -42, -4202, -42, -42, 42, 'Y',
			"21", 21, 0, 21, 0, 42, 32) == 85)
	{
		return (0);
	}
	return (1);
}

// test function:
int	printf_mixed_test(void)
{
	int	retval;

	retval = printing_test("%A%42%21%4242%15%2A%% "
			"%B%-42%-42-4202%4294967254%ffffffd6%2A%% "
			"%Y21%21%0%21%0%2A%%  %", "", &check_return_one);
	if (retval)
		return (retval);
	return (0);
}
