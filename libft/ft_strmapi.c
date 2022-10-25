/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:08:55 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 17:10:50 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*copy_s;
	unsigned int	i;

	if (s == NULL || !f)
		return (NULL);
	copy_s = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (copy_s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy_s[i] = f(i, s[i]);
		i++;
	}
	copy_s[i] = '\0';
	return (copy_s);
}
