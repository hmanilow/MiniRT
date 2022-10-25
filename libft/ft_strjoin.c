/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:32:45 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 17:19:00 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*s11;
	char	*s22;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s22 = (char *)s2;
	s11 = (char *)s1;
	str = (char *)malloc (ft_strlen(s11) + 1 + ft_strlen(s22));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s11) + 1);
	ft_strlcat(str, s2, ft_strlen(s22) + ft_strlen(s11) + 1);
	return (str);
}
