/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:06:14 by hmanilow          #+#    #+#             */
/*   Updated: 2021/10/25 18:26:20 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_of_n(int n)
{
	int	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	ft_otship(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*copy_char;
	int		znak;
	int		size;

	znak = 0;
	if (n < 0)
		znak = 1;
	size = ft_size_of_n(n);
	copy_char = (char *)malloc(sizeof(char) * (size + 1));
	if (copy_char == NULL)
		return (NULL);
	copy_char[size] = '\0';
	size--;
	while (size >= 0)
	{
		copy_char[size] = ft_otship(n % 10) + '0';
		n = ft_otship(n / 10);
		size--;
	}
	if (znak == 1)
		copy_char[0] = '-';
	return (copy_char);
}
