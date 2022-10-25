/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:58:37 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 16:58:42 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy_s;
	size_t	len_s;
	char	*sub;

	if (s == NULL)
		return (NULL);
	copy_s = (char *)s;
	len_s = ft_strlen(copy_s);
	if (start > len_s || !len)
		return (ft_calloc(1, sizeof(char)));
	if (len > start + (unsigned int)len_s)
		len = start + (unsigned int)len_s;
	sub = malloc (sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
