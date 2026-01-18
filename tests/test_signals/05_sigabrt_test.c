/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_sigabrt_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:49:44 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 13:33:48 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_signals.h"

int	sigabrt_test(void)
{
	abort();
	if (MAGIC_NUMBER)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
