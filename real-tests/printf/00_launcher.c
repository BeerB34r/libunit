/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslobodi <aslobodi@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:10:30 by mde-beer          #+#    #+#             */
/*   Updated: 2026/01/17 21:35:36 by aslobodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇                                           */
/*   ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀                                           */
/*   ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀⠀                                           */
/*   ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ——————————————————————————————                                           */
/* ************************************************************************** */

#include <framework.h>

// tests:
int	printf_basic_test(void);
int	printf_cflag_test(void);
int	printf_sflag_test(void);
int	printf_dflag_test(void);
int	printf_iflag_test(void);
int	printf_uflag_test(void);
int	printf_pflag_test(void);
int	printf_xlflag_test(void);
int	printf_xuflag_test(void);
int	printf_perflag_test(void);
int	printf_mixed_test(void);

// launcher:
int	printf_launcher(void)
{
	t_unit_ctx	*tests;

	tests = create_ctx("printf()");
	load_test(&tests, (t_test){.name = "Basic", .func = &printf_basic_test});
	load_test(&tests, (t_test){.name = "Flag %c", .func = &printf_cflag_test});
	load_test(&tests, (t_test){.name = "Flag %s", .func = &printf_sflag_test});
	load_test(&tests, (t_test){.name = "Flag %d", .func = &printf_dflag_test});
	load_test(&tests, (t_test){.name = "Flag %i", .func = &printf_iflag_test});
	load_test(&tests, (t_test){.name = "Flag %u", .func = &printf_uflag_test});
	load_test(&tests, (t_test){.name = "Flag %p", .func = &printf_pflag_test});
	load_test(&tests, (t_test){.name = "Flag %x", .func = &printf_xlflag_test});
	load_test(&tests, (t_test){.name = "Flag %X", .func = &printf_xuflag_test});
	load_test(&tests, (t_test){.name = "Flag %%",
		.func = &printf_perflag_test});
	load_test(&tests, (t_test){.name = "Mixed", .func = &printf_mixed_test});
	return (launch_tests(&tests));
}
