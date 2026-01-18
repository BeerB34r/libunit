/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   framework.h                                             :+:    :+:       */
/*                                                          +:+               */
/*   By: mde-beer <mde-beer@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/16 19:35:56 by mde-beer            #+#    #+#           */
/*   Updated: 2026/01/17 15:34:08 by mde-beer            ########   odam.nl   */
/*                                                                            */
/*   —————No norm compliance?——————                                           */
/*   ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝                                           */
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

#ifndef FRAMEWORK_H
# define FRAMEWORK_H

// subheaders
# include <constants.h>
# include <types.h>

// Porcelain
t_unit_ctx	*create_ctx(char *function_name);
void		load_test(t_unit_ctx **head, t_test test);
int			printing_test(
				const char *expected_stdout,
				const char *expected_stderr,
				t_testfunc func
				);
int			launch_tests(t_unit_ctx **head);
/*
 * int	example_launcher(void)
 * {
 * 	t_unit_ctx	*ctx;
 *
 * 	load_test(&ctx, (t_test){.name = "example", .func = &example_test});
 * 	return (launch_tests(&ctx));
 * }
 */

// Plumbing
char		*status(t_status status);
void		free_ctx(t_unit_ctx *ctx);
t_unit_ctx	*get_last(t_unit_ctx *ctx);
void		run_test(t_test	*test, t_unit_ctx *head);
t_status	map_signal_status(int sig);
int			map_status_retval(t_status stat);
t_status	map_retval_status(int retval);
void		log_test(const char *basename, t_test test);
// // Loggers
void		unknown_logger(t_test test, const int fd);
void		err_logger(t_test test, const int fd);
void		ok_logger(t_test test, const int fd);
void		ko_logger(t_test test, const int fd);
void		segv_logger(t_test test, const int fd);
void		bus_logger(t_test test, const int fd);
void		abrt_logger(t_test test, const int fd);
void		fpe_logger(t_test test, const int fd);
void		pipe_logger(t_test test, const int fd);
void		ill_logger(t_test test, const int fd);
void		time_logger(t_test test, const int fd);

#endif // FRAMEWORK_H
