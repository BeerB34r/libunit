/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akim <akim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:13:57 by akim              #+#    #+#             */
/*   Updated: 2026/01/18 18:37:19 by akim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// function to be tested:
char	**ft_split(const char *s, char c);

int	split_null_check_test(void)
{
	char	**str;

	str = ft_split("ABC 42", ' ');
	if (!str[2])
		return (0);
	else
		return (-1);
}
