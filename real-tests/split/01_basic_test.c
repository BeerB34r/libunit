/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:05:13 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 18:36:36 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

// function to be tested:
char	**ft_split(const char *s, char c);

int	split_basic_test(void)
{
	char	**str;

	str = ft_split("ABC 42", ' ');
	if (!ft_strncmp(str[0], "ABC", 3) && !ft_strncmp(str[1], "42", 2))
		return (0);
	else
		return (-1);
}
