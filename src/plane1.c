/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:16:07 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:22 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_intersect_plane2(t_plane *p, t_ray *r, t_bool bump,
								t_scene *scene)
{
	r->coordinates = ft_matrix3_addition(r->pos, ft_vector3_multiply(
				r->orient, r->t));
	r->color = p->color;
	ft_texture_plane(p, r, bump, scene);
}

//https://www.scratchapixel.com/lessons/3d-basic-rendering/
//minimal-r-tracer-rendering-simple-shapes/r-p-and-r-disk-intersection
void	ft_intersect_plane(t_plane *p, t_ray *r, t_bool bump, t_scene *scene)
{
	double		denom;
	double		t;

	denom = ft_vector3_scalar(p->orient, r->orient);
	if (denom > EPSILON)
	{
		t = ft_vector3_scalar(ft_matrix3_subtract(p->pos, r->pos),
				p->orient) / denom;
		if (t < EPSILON || (t + EPSILON > r->t))
			return ;
		r->normal = ft_vector3_negate(p->orient);
	}
	else if (denom < -EPSILON)
	{
		denom = ft_vector3_scalar(ft_vector3_negate(p->orient), r->orient);
		t = ft_vector3_scalar(ft_matrix3_subtract(p->pos, r->pos),
				ft_vector3_negate(p->orient)) / denom;
		if (t < EPSILON || (t + EPSILON > r->t))
			return ;
		r->normal = p->orient;
	}
	else
		return ;
	r->t = t;
	ft_intersect_plane2(p, r, bump, scene);
}

void	ft_add_plane(t_scene *scene, char *s)
{
	t_plane		*p;
	t_vector3	pos;
	t_vector3	orient;
	t_color		col;
	int			error;

	error = 0;
	pos = ft_new_vector_atof(&s, &error);
	orient = ft_new_vector_atof(&s, &error);
	ft_check_direction_limits(orient, &error);
	col = ft_new_color_atoc(&s, &error);
	ft_check_endline(&s, &error);
	if (error)
		ft_error(8);
	p = ft_new_plane(pos, orient, col);
	p->next = scene->planes;
	scene->planes = p;
}

t_plane	*ft_new_plane(t_vector3 pos, t_vector3 orient, t_color col)
{
	t_plane	*p;

	p = kd_calloc(1, sizeof(t_plane));
	if (p == NULL)
		ft_error(-1);
	p->pos = pos;
	p->orient = ft_vector3_normalise(orient);
	p->color = col;
	return (p);
}
