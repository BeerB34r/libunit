/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:05:13 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 20:54:39 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

// function to be tested:
char	**ft_split(const char *s, char c);

int	split_basic_test(void)
{
	char	**str;

	str = ft_split("ABC 42", ' ');
	if (!ft_strncmp(str[0], "ABC", 3) && !ft_strncmp(str[1], "42", 2))
	{
		if (str)
		{
			free(str[0]);
			free(str[1]);
			free(str);
		}
		return (0);
	}
	else
	{
		if (str)
		{
			free(str[0]);
			free(str[1]);
			free(str);
		}
		return (-1);
	}
}
