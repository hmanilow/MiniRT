/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:20:08 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 17:00:44 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ss(const char *set, char a)
{
	int	i;

	i = 0;
	while (set[i] && set[i] != a)
		i++;
	return (set[i] == a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*copy_s;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_ss(set, s1[i]))
		s1++;
	i = ft_strlen((char *)s1);
	while (i && ft_ss(set, s1[i - 1]))
		i--;
	copy_s = (char *)malloc (sizeof(char) * (i + 1));
	if (copy_s == NULL)
		return (NULL);
	ft_strlcpy(copy_s, s1, i + 1);
	return (copy_s);
}
