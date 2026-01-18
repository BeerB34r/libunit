/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sigbus_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:20:26 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 13:33:46 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_signals.h"

int	sigbus_test(void)
{
	FILE	*file;
	int		*ptr;
	int		fd;

	file = tmpfile();
	fd = fileno(file);
	ptr = mmap(NULL, MAGIC_NUMBER, PROT_WRITE, MAP_SHARED, fd, 0);
	*ptr = 0;
	if (MAGIC_NUMBER)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
