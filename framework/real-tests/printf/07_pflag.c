<<<<<<< HEAD
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
=======
#include <stddef.h> // symbol size_t
#include <framework.h>
#include <libft.h>

// function to be tested:
int	ft_printf(char const *str, ...);
>>>>>>> 17b4ba64c0f34d05feafe2a1312114b925774212

// helper tests
static
int	check_return_one(void)
{
<<<<<<< HEAD
	if (printf(" %p", NULL) == 6)
=======
	if (ft_printf("%uu%u", 0, 2147483647) == 12)
>>>>>>> 17b4ba64c0f34d05feafe2a1312114b925774212
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
<<<<<<< HEAD
	if (printf("%p", (void *)-28391422) == 18)
=======
	if (ft_printf("%u", -10) == 10)
>>>>>>> 17b4ba64c0f34d05feafe2a1312114b925774212
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
<<<<<<< HEAD
	if (printf("0x%p-", (void *)ULONG_MAX) == 21)
=======
    unsigned int n = 4294967295;
	if (ft_printf("%u", n) == 10)
>>>>>>> 17b4ba64c0f34d05feafe2a1312114b925774212
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
<<<<<<< HEAD
	if (printf("%pp%p%p", (void *)LONG_MAX + 423856,
			(void *)0, (void *)INT_MAX) == 34)
=======
	if (ft_printf("dgs%uxx", 10) == 7)
		return (0);
	return (1);
}

static
int	check_return_five(void)
{
	if (ft_printf("%u%uu%u", 1, 2, -3) == 13)
>>>>>>> 17b4ba64c0f34d05feafe2a1312114b925774212
		return (0);
	return (1);
}

// test function:
<<<<<<< HEAD
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
=======
int	ft_printf_pflag_test(void)
{
	int	retval;

	retval = printing_test("0u2147483647", "", &check_return_one);
	if (!retval)
		retval = printing_test("4294967286", "", &check_return_two);
	if (!retval)
		retval = printing_test("4294967295", "", &check_return_three);
	if (!retval)
		retval = printing_test("dgs10xx", "", &check_return_four);
	if (!retval)
		retval = printing_test("12u4294967293", "", &check_return_five);
	if (retval)
		return (retval);
	return (0);
}
>>>>>>> 17b4ba64c0f34d05feafe2a1312114b925774212
