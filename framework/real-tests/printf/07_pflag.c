#include <stddef.h> // symbol size_t
#include <framework.h>
#include <libft.h>

// function to be tested:
int	ft_printf(char const *str, ...);

// helper tests
static
int	check_return_one(void)
{
	if (ft_printf("%uu%u", 0, 2147483647) == 12)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (ft_printf("%u", -10) == 10)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
    unsigned int n = 4294967295;
	if (ft_printf("%u", n) == 10)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	if (ft_printf("dgs%uxx", 10) == 7)
		return (0);
	return (1);
}

static
int	check_return_five(void)
{
	if (ft_printf("%u%uu%u", 1, 2, -3) == 13)
		return (0);
	return (1);
}

// test function:
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