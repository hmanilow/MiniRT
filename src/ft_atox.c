/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:13:15 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:03 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_fraction_part(char **s, int *error)
{
	double	n;
	double	ten_power;

	n = 0;
	if (**s == '.')
	{
		(*s)++;
		ten_power = 1;
		while (**s && ft_isdigit(**s))
		{
			*error = 0;
			ten_power /= 10;
			n = n + ((**s - '0') * ten_power);
			(*s)++;
		}
	}
	return (n);
}

double	ft_atof(char **s, int *error)
{
	double	n;
	int		sign;
	int		local_error;

	while (ft_isspace(**s))
		(*s)++;
	sign = 1;
	local_error = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	n = 0;
	while (**s && ft_isdigit(**s))
	{
		local_error = 0;
		n = 10 * n + (**s - '0');
		(*s)++;
	}
	n += ft_fraction_part(s, &local_error);
	if (*error == 0)
		*error = local_error;
	return (n * sign);
}

unsigned char	ft_atoc(char **s, int *error)
{
	int	n;
	int	local_error;

	while (ft_isspace(**s))
		(*s)++;
	local_error = 1;
	if (**s == '+')
		(*s)++;
	n = 0;
	while (**s && ft_isdigit(**s))
	{
		local_error = 0;
		n = 10 * n + (**s - '0');
		(*s)++;
	}
	if (n > 255)
		local_error = 1;
	if (*error == 0)
		*error = local_error;
	return ((unsigned char) n);
}
