/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:12:52 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:00 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_cylinder_props(t_cylinder *cylinder, char *s)
{
	double	h;
	t_color	col;
	int		error;

	error = 0;
	h = ft_atof(&s, &error);
	col = ft_new_color_atoc(&s, &error);
	ft_check_endline(&s, &error);
	if (error)
		ft_error(9);
	cylinder->height = h;
	cylinder->color = col;
	cylinder->cap_bot.pos = cylinder->pos;
	cylinder->cap_bot.orient = ft_vector3_negate(cylinder->orient);
	cylinder->cap_bot.radius = cylinder->radius;
	cylinder->cap_bot.color = cylinder->color;
	cylinder->cap_top.pos = ft_matrix3_addition(cylinder->pos,
			ft_vector3_multiply(cylinder->orient, cylinder->height));
	cylinder->cap_top.orient = cylinder->orient;
	cylinder->cap_top.radius = cylinder->radius;
	cylinder->cap_top.color = cylinder->color;
}

void	ft_add_cylinder(t_scene *scene, char *str)
{
	t_cylinder	*cy;
	t_vector3	pos;
	t_vector3	orient;
	double		diam;
	int			error;

	error = 0;
	pos = ft_new_vector_atof(&str, &error);
	orient = ft_new_vector_atof(&str, &error);
	ft_check_direction_limits(orient, &error);
	diam = ft_atof(&str, &error);
	if (error)
		ft_error(9);
	cy = new_cylinder(pos, orient, diam / 2);
	add_cylinder_props(cy, str);
	cy->next = scene->cy;
	scene->cy = cy;
}

t_cylinder	*new_cylinder(t_vector3 position, t_vector3 orient, double radius)
{
	t_cylinder	*cylinder;

	cylinder = kd_calloc(1, sizeof(t_cylinder));
	if (cylinder == NULL)
		ft_error(-1);
	cylinder->pos = position;
	cylinder->orient = ft_vector3_normalise(orient);
	cylinder->radius = radius;
	return (cylinder);
}
