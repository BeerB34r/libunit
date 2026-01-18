/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_sigfpe_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:55:22 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 13:33:50 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_signals.h"

int	sigfpe_test(void)
{
	int	num;

	num = MAGIC_NUMBER;
	while (num)
		--num;
	num = num / num;
	if (num)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
