/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_empty_string_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:28:48 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 20:55:32 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

// function to be tested:
char	**ft_split(const char *s, char c);

int	split_empty_string_test(void)
{
	char	**str;

	str = ft_split("", ' ');
	if (!str[0])
	{
		if (str)
			free(str);
		return (0);
	}
	else
	{
		if (str)
		{
			if (str[0])
				free(str[0]);
			free(str);
		}
		return (-1);
	}
}
