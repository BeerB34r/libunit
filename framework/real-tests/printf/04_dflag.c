#include <stddef.h> // symbol size_t
#include <framework.h>
#include <libft.h>

// function to be tested:
int	printf(char const *str, ...);

// helper tests
static
int	check_return_one(void)
{
	if (printf("%d", 0) == 1)
		return (0);
	return (1);
}

static
int	check_return_two(void)
{
	if (printf("%d", -10) == 3)
		return (0);
	return (1);
}

static
int	check_return_three(void)
{
	if (printf("%d", -6000023) == 8)
		return (0);
	return (1);
}

static
int	check_return_four(void)
{
	if (printf("%d", 2147483647) == 10)
		return (0);
	return (1);
}

static
int	check_return_five(void)
{
    int n = -2147483648;
	if (printf("%ds", n) == 12)
		return (0);
	return (1);
}

// test function:
int	printf_dflag_test(void)
{
	int	retval;

	retval = printing_test("0", "", &check_return_one);
	if (!retval)
		retval = printing_test("-10", "", &check_return_two);
	if (!retval)
		retval = printing_test("-6000023", "", &check_return_three);
	if (!retval)
		retval = printing_test("2147483647", "", &check_return_four);
	if (!retval)
		retval = printing_test("-2147483648s", "", &check_return_five);
	if (retval)
		return (retval);
	return (0);
}