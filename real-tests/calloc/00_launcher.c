/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:45:34 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 19:57:47 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <framework.h>

// tests:
int	calloc_basic_test(void);
int	calloc_pointer_test(void);
int	calloc_null_test(void);

// launcher:
int	calloc_launcher(void)
{
	t_unit_ctx	*tests;

	tests = create_ctx("calloc()");
	load_test(&tests, (t_test){.name = "Basic",
		.func = &calloc_basic_test});
	load_test(&tests, (t_test){.name = "Pointer_test",
		.func = &calloc_pointer_test});
	load_test(&tests, (t_test){.name = "Null_test",
		.func = &calloc_null_test});
	return (launch_tests(&tests));
}
