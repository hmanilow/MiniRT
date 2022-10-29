/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:12:41 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:18:57 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	ft_intersect_cone2(t_ray tmp_ray, t_cone *cone, t_ray *ray)
{
	if (!(cone->theta < M_PI_2 && ft_vector3_scalar(ft_matrix3_subtract(
					tmp_ray.coordinates, cone->pos), cone->orient)
			> -EPSILON))
		return ;
	if (ft_vector3_sumpow2(ft_matrix3_subtract(tmp_ray.coordinates, cone->pos))
		> pow(cone->height / cone->costheta, 2))
		return ;
	*ray = tmp_ray;
	ray->normal = ft_vector3_normalise(ft_matrix3_subtract(ray->coordinates,
				ft_matrix3_addition(cone->pos, ft_vector3_multiply(
						cone->orient, ft_vector3_distance(ray->coordinates,
							cone->pos) / cone->costheta))));
	if (ft_vector3_scalar(ft_matrix3_subtract(ray->pos, cone->pos),
			cone->orient) > 0)
		ray->normal = ft_vector3_negate(ray->normal);
	ray->color = cone->color;
}

// q.d < 0 нет пересечений, [t1,t2] < 0 отрезает заднее отзеркаливание
// || удаляет результат если ранее был найден объект с пересечением ближе конуса
// отрезает конус-двойник
// ограничевает конус по высоте
void	ft_intersect_cone(t_cone *cone, t_ray *ray, t_scene *scene)
{
	t_ray		tmp_ray;
	t_quad		q;
	t_vector3	v_c2r;

	ft_intersect_disc(&cone->cap, ray, scene);
	v_c2r = ft_matrix3_subtract(ray->pos, cone->pos);
	q.a = pow(ft_vector3_scalar(ray->orient, cone->orient), 2)
		- cone->pow2costheta;
	q.b = 2 * (ft_vector3_scalar(ray->orient, cone->orient)
			* ft_vector3_scalar(v_c2r,
				cone->orient) - ft_vector3_scalar(ray->orient, v_c2r)
			* cone->pow2costheta);
	q.c = pow(ft_vector3_scalar(v_c2r, cone->orient), 2)
		- ft_vector3_scalar(v_c2r, v_c2r) * cone->pow2costheta;
	tmp_ray = *ray;
	tmp_ray.t = ft_math_quadratic_equation(&q);
	if (q.t1 > EPSILON && q.t2 > EPSILON && ft_vector3_scalar(ray->orient,
			cone->orient) > 0)
		tmp_ray.t = q.t2;
	if (tmp_ray.t < EPSILON || tmp_ray.t + EPSILON > ray->t)
		return ;
	tmp_ray.coordinates = ft_matrix3_addition(ray->pos, ft_vector3_multiply(
				ray->orient, tmp_ray.t));
	ft_intersect_cone2(tmp_ray, cone, ray);
}

void	ft_add_cone_props(t_cone *cone, char *s)
{
	double	h;
	t_color	color;
	int		error;

	error = 0;
	h = ft_atof(&s, &error);
	color = ft_new_color_atoc(&s, &error);
	ft_check_endline(&s, &error);
	if (error)
		ft_error(9);
	cone->height = h;
	cone->color = color;
	cone->cap.pos = ft_matrix3_addition(cone->pos,
			ft_vector3_multiply(cone->orient, cone->height));
	cone->cap.orient = cone->orient;
	cone->cap.radius = cone->radius;
	cone->cap.color = cone->color;
	cone->theta = atan(cone->radius / cone->height);
	cone->costheta = cos(cone->theta);
	cone->pow2costheta = pow(cone->costheta, 2);
}

void	ft_add_cone(t_scene *scene, char *s)
{
	t_cone		*cone;
	t_vector3	pos;
	t_vector3	orient;
	double		diametr;
	int			error;

	error = 0;
	pos = ft_new_vector_atof(&s, &error);
	orient = ft_new_vector_atof(&s, &error);
	ft_check_direction_limits(orient, &error);
	diametr = ft_atof(&s, &error);
	if (error)
		ft_error(9);
	cone = ft_new_cone(pos, orient, diametr / 2);
	ft_add_cone_props(cone, s);
	cone->next = scene->cones;
	scene->cones = cone;
}

t_cone	*ft_new_cone(t_vector3 position, t_vector3 orient, double rad)
{
	t_cone	*cone;

	cone = kd_calloc(1, sizeof(t_cone));
	if (cone == NULL)
		ft_error(-1);
	cone->pos = position;
	cone->orient = ft_vector3_normalise(orient);
	cone->radius = rad;
	return (cone);
}
