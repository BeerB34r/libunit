#include <stddef.h> // symbol size_t
#include <framework.h>
#include <libft.h>

// function to be tested:
int	ft_printf(char const *str, ...);

// helper tests
static
int	check_return_one(void)
{
	if (ft_printf("%c", 'x') == 1)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (ft_printf(" %c", 'x') == 2)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
	if (ft_printf("%c%c%c", 'a', ' ', 'b') == 3)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	if (ft_printf("%cc%cc%c", 'a', ' ', 'b') == 5)
		return (0);
	return (1);
}

static
int	check_return_five(void)
{
	if (ft_printf("%cs%cs%c", 'a', ' ', 'b') == 5)
		return (0);
	return (1);
}

// test function:
int	ft_printf_sflag_test(void)
{
	int	retval;

	retval = printing_test("x", "", &check_return_one);
	if (!retval)
		retval = printing_test(" x", "", &check_return_two);
	if (!retval)
		retval = printing_test("a b", "", &check_return_three);
	if (!retval)
		retval = printing_test("ac cb", "", &check_return_four);
	if (!retval)
		retval = printing_test("as sb", "", &check_return_five);
	if (retval)
		return (retval);
	return (0);
}
