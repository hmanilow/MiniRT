/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_uts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:12:13 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:18:49 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_col_amplify(t_color col, double amplifier)
{
	col.r *= amplifier;
	col.g *= amplifier;
	col.b *= amplifier;
	return (col);
}

t_color	ft_col_add(t_color col, t_color col_add)
{
	col.r += col_add.r;
	col.g += col_add.g;
	col.b += col_add.b;
	return (col);
}

t_color	ft_colour_matrix_amplify(t_color col, t_color col_amplifier)
{
	int	mix;

	mix = 10;
	col.r = col.r * col_amplifier.r / 255
		+ col_amplifier.g / mix + col_amplifier.b / mix;
	col.g = col.g * col_amplifier.g / 255
		+ col_amplifier.r / mix + col_amplifier.b / mix;
	col.b = col.b * col_amplifier.b / 255
		+ col_amplifier.r / mix + col_amplifier.g / mix;
	return (col);
}

t_color	ft_colour_gamma_collect(t_color col, t_scene *scene)
{
	scene->gamma = fmax(scene->gamma,
			kd_max(kd_max(col.r, col.g), col.b) / (double)255);
	return (col);
}

t_color	ft_colour_gamma_apply(t_color col, t_scene *scene)
{
	if (scene->gamma_correction)
	{
		col.r /= scene->gamma;
		col.g /= scene->gamma;
		col.b /= scene->gamma;
		return (col);
	}
	else
		return (ft_colour_clamp(col));
}
