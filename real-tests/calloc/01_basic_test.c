/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:05:13 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 20:33:28 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// function to be tested:
void	*ft_calloc(size_t nmemb, size_t size);

int	calloc_basic_test(void)
{
	char	*str;

	str = ft_calloc(1, 8);
	if (!ft_memcmp(str, "\0\0\0\0\0\0\0\0", 8))
	{
		if (str)
			free(str);
		return (0);
	}
	else
	{
		if (str)
			free(str);
		return (-1);
	}
}
