/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:52:14 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 19:52:43 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdint.h>

// function to be tested:
void	*ft_calloc(size_t nmemb, size_t size);

int	calloc_null_test(void)
{
	char	*str;

	str = ft_calloc(SIZE_MAX, 8);
	if (!str)
		return (0);
	else
		return (-1);
}
