/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_pointer_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:13:57 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 20:44:05 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

// function to be tested:
void	*ft_calloc(size_t nmemb, size_t size);

int	calloc_pointer_test(void)
{
	char	*str;

	str = ft_calloc(1, 8);
	if (str)
	{
		free(str);
		return (0);
	}
	else
		return (-1);
}
