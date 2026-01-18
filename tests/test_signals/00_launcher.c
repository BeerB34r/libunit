/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:37:02 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 13:48:07 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework.h"
#include "test_signals.h" // tests

int	test_signals_launcher(void) // launcher
{
	t_unit_ctx	*tests;

	tests = create_ctx("signal_tester");
	load_test(&tests, (t_test){.name = "OK_test", .func = &ok_test});
	load_test(&tests, (t_test){.name = "KO_test", .func = &ko_test});
	load_test(&tests, (t_test){.name = "SIGSEGV_test", .func = &sigsegv_test});
	load_test(&tests, (t_test){.name = "SIGBUS_test", .func = &sigbus_test});
	load_test(&tests, (t_test){.name = "SIGABRT_test", .func = &sigabrt_test});
	load_test(&tests, (t_test){.name = "SIGFPE_test", .func = &sigfpe_test});
	load_test(&tests, (t_test){.name = "SIGPIPE_test", .func = &sigpipe_test});
	load_test(&tests, (t_test){.name = "SIGILL_test", .func = &sigill_test});
	return (launch_tests(&tests));
}
