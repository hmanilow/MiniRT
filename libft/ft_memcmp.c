/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:43:13 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 18:20:41 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a1;
	const unsigned char	*a2;
	size_t				i;

	if (n == 0 || s1 == s2)
		return (0);
	a1 = (const unsigned char *)s1;
	a2 = (const unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		if (n != 0)
		{
			a1++;
			a2++;
		}
	}
	return (0);
}
