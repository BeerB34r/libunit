/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:45:34 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 18:11:22 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <framework.h>

// tests:
int	split_basic_test(void);
int	split_null_check_test(void);
int	split_consecutive_char_test(void);
int	split_newline_test(void);
int	split_empty_string_test(void);

// launcher:
int	split_launcher(void)
{
	t_unit_ctx	*tests;

	tests = create_ctx("split()");
	load_test(&tests, (t_test){.name = "Basic",
		.func = &split_basic_test});
	load_test(&tests, (t_test){.name = "Null_check",
		.func = &split_null_check_test});
	load_test(&tests, (t_test){.name = "Big_string",
		.func = &split_consecutive_char_test});
	load_test(&tests, (t_test){.name = "Newline",
		.func = &split_newline_test});
	load_test(&tests, (t_test){.name = "Empty_string",
		.func = &split_empty_string_test});
	return (launch_tests(&tests));
}
