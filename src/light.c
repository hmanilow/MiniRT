/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:05 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:13 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_add_light_back(t_light **lights, t_light *light)
{
	t_light	*ligh;

	if (!*lights)
		*lights = light;
	else
	{
		ligh = *lights;
		while (ligh->next)
			ligh = ligh->next;
		ligh->next = light;
	}
}

void	ft_ft_add_light(t_scene *scene, char *s)
{
	t_vector3	pos;
	double		bright;
	t_color		col;
	int			error;

	if (!BONUS && scene->light != NULL)
		ft_error(7);
	error = 0;
	pos = ft_new_vector_atof(&s, &error);
	bright = ft_atof(&s, &error);
	ft_check_ratio_limits(bright, &error);
	col = ft_new_light_color_atoc(&s, &error);
	ft_check_endline(&s, &error);
	if (error)
		ft_error(7);
	ft_add_light_back(&scene->light, ft_new_light(pos, bright, col));
	scene->cur_light = scene->light;
}

t_light	*ft_new_light(t_vector3 pos, double bright, t_color col)
{
	t_light	*light;

	light = kd_calloc(1, sizeof(t_light));
	if (light == NULL)
		ft_error(-1);
	light->pos = pos;
	light->bright = bright;
	light->color = col;
	return (light);
}
