/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:16:58 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 19:04:26 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fr_free(char **mas, int pos)
{
	while (pos)
	{
		free(mas[pos]);
		pos--;
	}
	free(mas);
	return (-7);
}

void	w_rewrite(char *str_of_pos, const char *s, char c)
{
	int	i;

	i = 0;
	while (!(s[i] == c || s[i] == '\0'))
	{
		str_of_pos[i] = s[i];
		i++;
	}
	str_of_pos[i] = '\0';
}

int	ft_splitette(char **mas, const char *s, char c)
{
	int	i;
	int	j;
	int	pos;

	pos = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\0' || s[i] == c)
			i++;
		else
		{
			j = 0;
			while (!(s[i + j] == c || s[i + j] == '\0'))
				j++;
			mas[pos] = (char *)malloc(sizeof(char) * (j + 1));
			if (mas[pos] == NULL)
				return (ft_fr_free(mas, pos));
			w_rewrite(mas[pos], s + i, c);
			pos++;
			i += j;
		}
	}
	return (0);
}

int	ft_count_words(const char *s, char c)
{
	int	count_words;
	int	i;

	i = 0;
	count_words = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == '\0' || s[i] == c)
			&& (s[i + 1] == '\0' || s[i + 1] == c))
			count_words++;
		i++;
	}
	return (count_words);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**mas;

	if (s == NULL)
		return (NULL);
	count = ft_count_words(s, c);
	mas = (char **)malloc(sizeof(char *) * (count + 1));
	if (mas == NULL)
		return (NULL);
	mas[count] = 0;
	if (ft_splitette(mas, s, c) == -7)
		return (NULL);
	return (mas);
}
