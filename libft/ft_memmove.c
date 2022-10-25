/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:30:38 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 18:15:48 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ft(unsigned char *a1, unsigned char *a2, size_t len)
{
	size_t	i;

	i = 1;
	while (i <= len)
	{
		a1[len - i] = a2[len - i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a1;
	unsigned char	*a2;
	size_t			i;

	a1 = (unsigned char *)dst;
	a2 = (unsigned char *)src;
	if (a1 > a2)
		ft_ft(a1, a2, len);
	else if (src || dst)
	{
		i = 0;
		while (i < len)
		{
			a1[i] = a2[i];
			i++;
		}
	}
	else if (a1 == a2)
		return (0);
	return (dst);
}
