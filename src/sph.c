/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:17:27 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:35 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_bump(t_ray *r, double u, double v, t_scene *scene)
{
	r->normal = ft_vector3_qrotate(r->normal, sin(u * M_PI_2 * 360) * 10,
			ft_vector3_cw(r->normal));
	r->normal = ft_vector3_qrotate(r->normal, sin(v * M_PI_2 * 180) * 10,
			ft_vector3_cw(r->normal));
	(void)scene;
}

static t_color	ft_texture_sphere(t_sphere *sp, t_ray *r, t_scene *scene)
{
	double	uf;
	double	vf;
	double	u;
	double	v;

	if (!scene->checkerboard && !scene->bump)
		return (sp->color);
	u = 0.5 + atan2((r->coordinates.z - sp->pos.z) / sp->radius,
			(r->coordinates.x - sp->pos.x) / sp->radius)
		/ (2 * M_PI);
	v = 0.5 - asin((r->coordinates.y - sp->pos.y) / sp->radius)
		/ M_PI;
	if (scene->bump)
		ft_bump(r, u, v, scene);
	if (!scene->checkerboard)
		return (sp->color);
	uf = floor(fmod(u * 18, 2));
	vf = floor(fmod(v * 9, 2));
	if ((uf && vf) || (!uf && !vf))
		return (ft_new_color(255, 255, 255));
	else
		return (ft_new_color(0, 0, 0));
}

void	ft_intersect_sphere(t_sphere *sp, t_ray *r, t_scene *scene)
{
	t_ray		tmp_ray;
	t_vector3	d;
	t_vector3	p;
	t_quad		q;

	d = r->orient;
	p = ft_matrix3_subtract(r->pos, sp->pos);
	q.a = ft_vector3_sumpow2(d);
	q.b = 2 * d.x * p.x + 2 * d.y * p.y + 2 * d.z * p.z;
	q.c = ft_vector3_sumpow2(sp->pos) + ft_vector3_sumpow2(r->pos)
		- 2 * ft_vector3_scalar(sp->pos, r->pos)
		- pow(sp->radius, 2);
	tmp_ray = *r;
	tmp_ray.t = ft_math_quadratic_equation(&q);
	if (tmp_ray.t < EPSILON || tmp_ray.t + EPSILON > r->t)
		return ;
	*r = tmp_ray;
	r->coordinates = ft_matrix3_addition(r->pos, ft_vector3_multiply(d, r->t));
	if (fmin(q.t1, q.t2) > EPSILON)
		r->normal = ft_vector3_normalise(ft_matrix3_subtract(r->coordinates,
					sp->pos));
	else
		r->normal = ft_vector3_normalise(ft_matrix3_subtract(sp->pos,
					r->coordinates));
	r->color = ft_texture_sphere(sp, r, scene);
}

void	ft_add_sphere(t_scene *scene, char *s)
{
	t_sphere	*sp;
	float		diam;
	int			error;
	t_vector3	center;
	t_color		col;

	error = 0;
	center = ft_new_vector_atof(&s, &error);
	diam = ft_atof(&s, &error);
	col = ft_new_color_atoc(&s, &error);
	ft_check_endline(&s, &error);
	if (error)
		ft_error(3);
	sp = ft_new_sphere(center, diam / 2, col);
	sp->next = scene->sph;
	scene->sph = sp;
}

t_sphere	*ft_new_sphere(t_vector3 pos, double radius, t_color col)
{
	t_sphere	*sp;

	sp = kd_calloc(1, sizeof(t_sphere));
	if (sp == NULL)
		ft_error(-1);
	sp->pos = pos;
	sp->radius = radius;
	sp->color = col;
	return (sp);
}
