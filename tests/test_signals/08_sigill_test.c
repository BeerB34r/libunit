/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_sigill_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:35:14 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 13:33:59 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_signals.h"

int	sigill_test(void)
{
	asm("ud2");
	if (MAGIC_NUMBER)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
