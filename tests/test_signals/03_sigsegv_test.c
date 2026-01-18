/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_sigsegv_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:03:18 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 13:49:40 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_signals.h"

int	sigsegv_test(void)
{
	int		i;
	int		ch;
	char	*ptr;

	ptr = NULL;
	i = 0;
	while (i < MAGIC_NUMBER)
		ch = ptr[++i];
	if (MAGIC_NUMBER)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
