/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:44:52 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 19:04:53 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_neddle;
	char	*ned;
	char	*h;

	if (!*needle || *needle == '\n' || haystack == needle)
		return ((char *)haystack);
	ned = (char *)needle;
	len_neddle = ft_strlen(ned);
	h = (char *)haystack;
	i = 0;
	j = 0;
	while (i < len && haystack[i] != '\0')
	{
		while (j + i < len && needle[j] == haystack[i + j]
			&& needle[j] != '\0' && haystack[i + j] != '\0')
			j++;
		if (j == len_neddle)
			return (h + i);
		j = 0;
		i++;
	}
	return (NULL);
}
