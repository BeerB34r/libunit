/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_consecutive_char_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:52:14 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 18:37:57 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// function to be tested:
char	**ft_split(const char *s, char c);

int	split_consecutive_char_test(void)
{
	char	**str;

	str = ft_split("  A  B  ", ' ');
	if (!ft_strncmp(str[0], "A", 1) && !ft_strncmp(str[1], "B", 1))
		return (0);
	else
		return (-1);
}
