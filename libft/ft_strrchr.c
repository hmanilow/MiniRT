/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:58:26 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 17:02:49 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*a;
	void				*pointer;

	pointer = NULL;
	c = (unsigned char )c;
	a = (const unsigned char *)s;
	while (*a != '\0')
	{
		if (*a == c)
			pointer = (void *)a;
		a++;
	}
	if (*a == '\0' && c == '\0')
	{
		pointer = (void *)a;
		return (pointer);
	}
	return (pointer);
}
