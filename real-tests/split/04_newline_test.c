/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_newline_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:15:21 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 20:44:29 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

// function to be tested:
char	**ft_split(const char *s, char c);

int	split_newline_test(void)
{
	char	**str;

	str = ft_split("ABC \n", ' ');
	if (!ft_strncmp(str[1], "\n", 1))
	{
		if (str)
		{
			if (str[0])
				free(str[0]);
			if (str[1])
				free(str[1]);
			free(str);
		}
		return (0);
	}
	else
	{
		if (str)
		{
			if (str[0])
				free(str[0]);
			if (str[1])
				free(str[1]);
			free(str);
		}
		return (-1);
	}
}
