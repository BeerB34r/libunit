/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_newline_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:15:21 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 18:37:46 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// function to be tested:
char	**ft_split(const char *s, char c);

int	split_newline_test(void)
{
	char	**str;

	str = ft_split("ABC \n", ' ');
	if (!ft_strncmp(str[1], "\n", 1))
		return (0);
	else
		return (-1);
}
