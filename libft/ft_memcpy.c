/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:57:51 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 18:18:48 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cpy_dst;
	const char	*cpy_src;

	if (!dst && !src)
		return (NULL);
	cpy_dst = (char *)dst;
	cpy_src = (const char *)src;
	while (n-- > 0)
		*cpy_dst++ = *cpy_src++;
	return (dst);
}
