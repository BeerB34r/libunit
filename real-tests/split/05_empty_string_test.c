/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_empty_string_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:28:48 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 18:38:17 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// function to be tested:
char	**ft_split(const char *s, char c);

int	split_empty_string_test(void)
{
	char	**str;

	str = ft_split("", ' ');
	if (!str[0])
		return (0);
	else
		return (-1);
}
