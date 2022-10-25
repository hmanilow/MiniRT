/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:32:45 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 17:25:16 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*a;
	void				*pointer;

	c = (unsigned char )c;
	a = (const unsigned char *)s;
	while (*a != '\0')
	{
		if (*a == c)
		{
			pointer = (void *)a;
			return (pointer);
		}
		a++;
	}
	if (*a == '\0' && c == '\0')
	{
		pointer = (void *)a;
		return (pointer);
	}
	return (0);
}
