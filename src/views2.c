/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:18:05 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:36:57 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_ray_perspective_quaternion(t_scene *scene, int x, int y, t_ray *r)
{
	double		theta;
	double		radius;
	t_vector2	step;
	t_vector3	axis;

	r->pos = scene->cam->pos;
	radius = sqrt(pow(scene->width / (double)2, 2) + pow(scene->height
				/ (double)2, 2));
	step.u = (x - scene->width / (double)2) / radius;
	step.v = (y - scene->height / (double)2) / radius;
	theta = sqrt(pow(step.u, 2) + pow(step.v, 2)) * scene->cam->fov / 2;
	axis = ft_vector3_normalise(ft_new_vector3(step.v, step.u, 0));
	r->orient = ft_vector3_qrotate(ft_new_vector3(0, 0, 1), theta, axis);
	r->orient = ft_vector3_rotate_yx(r->orient, scene->cam->rot);
}

void	ft_ray_perspective_quaternion2(t_scene *scene, int x, int y, t_ray *r)
{
	double		theta;
	double		radius;
	t_vector2	step;
	t_vector3	axis;

	r->pos = scene->cam->pos;
	radius = fmax(scene->width / (double)2, scene->height / (double)2);
	step.u = (x - scene->width / (double)2) / radius;
	step.v = (y - scene->height / (double)2) / radius;
	theta = sqrt(pow(step.u, 2) + pow(step.v, 2)) * scene->cam->fov / 2;
	axis = ft_vector3_normalise(ft_new_vector3(step.v, step.u, 0));
	r->orient = ft_vector3_qrotate(ft_new_vector3(0, 0, 1), theta, axis);
	r->orient = ft_vector3_rotate_yx(r->orient, scene->cam->rot);
}
