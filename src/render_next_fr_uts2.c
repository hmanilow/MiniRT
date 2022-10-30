/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_fr_uts2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:16:37 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:32 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_math_quadratic_equation(t_quad *q)
{
	q->t1 = 0;
	q->t2 = 0;
	q->d = pow(q->b, 2) - 4 * q->a * q->c;
	if (q->d < 0 && q->d > -EPSILON)
		q->d = 0;
	if (q->d < 0)
		return (-1);
	q->sqrt_d = sqrt(q->d);
	q->t1 = (-q->b - q->sqrt_d) / (2 * q->a);
	q->t2 = (-q->b + q->sqrt_d) / (2 * q->a);
	if (fmin(q->t1, q->t2) > EPSILON)
		return (fmin(q->t1, q->t2));
	return (fmax(q->t1, q->t2));
}

void	ft_intersect_disc(t_disc *disc, t_ray *r, t_scene *scene)
{
	t_ray	tmp_ray;
	t_plane	p;

	p.pos = disc->pos;
	p.orient = disc->orient;
	p.color = disc->color;
	tmp_ray = *r;
	ft_intersect_plane(&p, &tmp_ray, FALSE, scene);
	if (tmp_ray.t + EPSILON > r->t)
		return ;
	if (ft_vector3_sumpow2(ft_matrix3_subtract(
				tmp_ray.coordinates, disc->pos)) > pow(disc->radius, 2))
		return ;
	*r = tmp_ray;
}

void	ft_intersect2(t_ray *r, t_scene *scene)
{
	t_cone		*cone;
	t_cylinder	*cy;

	cone = scene->cones;
	while (cone)
	{
		ft_intersect_cone(cone, r, scene);
		cone = cone->next;
	}
	cy = scene->cy;
	while (cy)
	{
		ft_intersect_cylinder(cy, r, scene);
		cy = cy->next;
	}
}

void	ft_intersect(t_ray *r, t_scene *scene)
{
	t_plane		*p;
	t_sphere	*s;

	p = scene->planes;
	while (p)
	{
		ft_intersect_plane(p, r, scene->bump, scene);
		p = p->next;
	}
	s = scene->sph;
	while (s)
	{
		ft_intersect_sphere(s, r, scene);
		s = s->next;
	}
	ft_intersect2(r, scene);
}
