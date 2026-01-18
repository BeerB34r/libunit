/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signals.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:38:39 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 13:49:54 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_SIGNALS_H
# define TEST_SIGNALS_H
# define EXIT_SUCCESS 0
# define EXIT_FAILURE -1
# define MAGIC_NUMBER 42
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <sys/mman.h>

int	ok_test(void);
int	ko_test(void);
int	sigsegv_test(void);
int	sigbus_test(void);
int	sigabrt_test(void);
int	sigfpe_test(void);
int	sigpipe_test(void);
int	sigill_test(void);

#endif // TEST_SIGNALS_H
