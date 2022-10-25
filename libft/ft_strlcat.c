/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:46:03 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 17:17:23 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*srcsrc;

	i = 0;
	srcsrc = (char *)src;
	while (dst[i] != '\0' && i < size)
		i++;
	j = 0;
	while (src[j] != '\0' && j + i + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (j > 0)
		dst[i + j] = '\0';
	return (i + ft_strlen(srcsrc));
}
