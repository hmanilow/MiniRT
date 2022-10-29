/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:12:24 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:18:53 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_new_color(int r, int g, int b)
{
	t_color	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (ft_colour_clamp(res));
}

t_color	ft_new_light_color_atoc(char **str, int *err)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '\0')
	{
		ft_putstr_fd("Color of light isnt selected.Init with white\n", 1);
		return (ft_new_color(255, 255, 255));
	}
	if (!BONUS)
		ft_error(10);
	return (ft_new_color_atoc(str, err));
}

t_color	ft_new_color_atoc(char **s, int *error)
{
	int	r;
	int	g;
	int	b;

	while (ft_isspace(**s))
		(*s)++;
	if (**s == ',')
		(*s)++;
	if (**s == '\0' && BONUS)
	{
		ft_putstr_fd("Color not specified. Init with white color\n", 1);
		return (ft_new_color(255, 255, 255));
	}
	r = ft_atoc(s, error);
	if (**s == ',')
		(*s)++;
	g = ft_atoc(s, error);
	if (**s == ',')
		(*s)++;
	b = ft_atoc(s, error);
	return (ft_new_color(r, g, b));
}

t_color	ft_colour_clamp(t_color col)
{
	if (col.r < 0)
		col.r = 0;
	else if (col.r > 255)
		col.r = 255;
	if (col.g < 0)
		col.g = 0;
	else if (col.g > 255)
		col.g = 255;
	if (col.b < 0)
		col.b = 0;
	else if (col.b > 255)
		col.b = 255;
	return (col);
}
