/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:12:47 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:18:59 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_is_in_cutted_cylinder(t_cylinder *cy, t_ray *ray, t_quad q)
{
	t_vector3	qq;

	qq = ft_matrix3_addition(ray->pos,
			ft_vector3_multiply(ray->orient, ray->t));
	if ((ft_vector3_scalar(cy->orient, ft_matrix3_subtract(qq,
					cy->cap_bot.pos)) > 0) && (ft_vector3_scalar(
				cy->orient, ft_matrix3_subtract(qq,
					cy->cap_top.pos)) < 0))
		return (1);
	if (q.t2 == 0)
		return (0);
	ray->t = q.t2;
	qq = ft_matrix3_addition(ray->pos,
			ft_vector3_multiply(ray->orient, ray->t));
	if ((ft_vector3_scalar(cy->orient, ft_matrix3_subtract(qq,
					cy->cap_bot.pos)) > 0) && (ft_vector3_scalar(
				cy->orient, ft_matrix3_subtract(qq,
					cy->cap_top.pos)) < 0))
		return (1);
	return (0);
}

void	ft_init_cylinder_q(t_cylinder *cy, t_ray	*ray, t_quad *q)
{
	t_vector3	p;

	p = ft_matrix3_subtract(ray->pos, cy->pos);
	q->a = ft_vector3_sumpow2(ft_matrix3_subtract(ray->orient,
				ft_vector3_multiply(cy->orient,
					ft_vector3_scalar(ray->orient, cy->orient))));
	q->b = 2 * (ft_vector3_scalar(ft_matrix3_subtract(ray->orient,
					ft_vector3_multiply(cy->orient, ft_vector3_scalar(
							ray->orient, cy->orient))),
				ft_matrix3_subtract(p, ft_vector3_multiply(cy->orient,
						ft_vector3_scalar(p, cy->orient)))));
	q->c = ft_vector3_sumpow2(ft_matrix3_subtract(p, ft_vector3_multiply(
					cy->orient, ft_vector3_scalar(p, cy->orient))))
		- pow(cy->radius, 2);
}

void	ft_intersect_cylinder(t_cylinder *cy, t_ray *ray, t_scene *scene)
{
	t_ray		tmp_ray;
	t_quad		q;
	t_vector3	op;

	ft_intersect_disc(&cy->cap_bot, ray, scene);
	ft_intersect_disc(&cy->cap_top, ray, scene);
	tmp_ray = *ray;
	ft_init_cylinder_q(cy, &tmp_ray, &q);
	tmp_ray.t = ft_math_quadratic_equation(&q);
	if (tmp_ray.t < EPSILON || tmp_ray.t + EPSILON > ray->t)
		return ;
	if (ft_is_in_cutted_cylinder(cy, &tmp_ray, q) != 1)
		return ;
	if (tmp_ray.t < EPSILON || tmp_ray.t + EPSILON > ray->t)
		return ;
	tmp_ray.coordinates = ft_matrix3_addition(ray->pos, ft_vector3_multiply(
				ray->orient, tmp_ray.t));
	*ray = tmp_ray;
	op = ft_matrix3_subtract(ray->coordinates, cy->pos);
	ray->normal = ft_vector3_normalise(ft_matrix3_subtract(op,
				ft_vector3_multiply(cy->orient,
					ft_vector3_scalar(cy->orient, op))));
	if (tmp_ray.t == q.t2)
		ray->normal = ft_vector3_negate(ray->normal);
	ray->color = cy->color;
}
