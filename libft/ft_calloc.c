/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:40:44 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 18:29:39 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	char	*str;
	char	c;
	size_t	len;

	s = malloc(size * count);
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	len = count * size;
	c = '\0';
	while (len > 0)
	{
		str[len - 1] = c;
		len--;
	}
	return (s);
}
