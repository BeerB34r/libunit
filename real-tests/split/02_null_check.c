/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:13:57 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 20:55:02 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

// function to be tested:
char	**ft_split(const char *s, char c);

int	split_null_check_test(void)
{
	char	**str;

	str = ft_split("ABC 42", ' ');
	if (!str[2])
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
