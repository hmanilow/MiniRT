/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:18:00 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:40:37 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_ray_orthographic(t_camera *cam, t_vector2 step, t_ray *r)
{
	r->pos.x = cam->pos.x + step.u * cam->zoom;
	r->pos.y = cam->pos.y + step.v * cam->zoom;
	r->pos.z = cam->pos.z;
	r->pos = ft_matrix3_addition(
			ft_vector3_rotate_yx(ft_matrix3_subtract(r->pos, cam->pos),
				cam->rot), cam->pos);
	r->orient = ft_vector3_rotate_yx(ft_new_vector3(0, 0, 1), cam->rot);
}

void	ft_ray_perspective_tan(t_camera *cam, t_vector2 step, t_ray *r)
{
	r->pos = cam->pos;
	r->orient = ft_new_vector3(tan(cam->fov / 2 * (M_PI / 180))
			* step.u, tan(cam->fov / 2 * (M_PI / 180)) * step.v, 1);
	r->orient = ft_vector3_normalise(r->orient);
	r->orient = ft_vector3_rotate_yx(r->orient, cam->rot);
}

void	ft_ray_perspective_spherise(t_camera *cam, t_vector2 step, t_ray *r)
{
	r->pos = cam->pos;
	step.v = cam->fov / 2 * step.v;
	step.u = cam->fov / 2 * step.u;
	r->orient = ft_vector3_rotate_yx(ft_new_vector3(0, 0, 1), step);
	r->orient = ft_vector3_rotate_yx(r->orient, cam->rot);
}

void	ft_ray_perspective_spherise2(t_camera *cam, t_vector2 step, t_ray *r)
{
	r->pos = cam->pos;
	step.v = cam->fov / 2 * step.v * (0.5 + 0.5 * cos(M_PI_2
				* fabs(step.u)));
	step.u = cam->fov / 2 * step.u;
	r->orient = ft_vector3_rotate_yx(ft_new_vector3(0, 0, 1), step);
	r->orient = ft_vector3_rotate_yx(r->orient, cam->rot);
}

void	ft_ray_perspective_spherise3(t_camera *cam, t_vector2 step, t_ray *r)
{
	t_vector3	tempy;
	t_vector3	tempx;

	r->pos = cam->pos;
	step.v = cam->fov / 2 * step.v;
	step.u = cam->fov / 2 * step.u;
	tempy = ft_vector3_rotate_yx(ft_new_vector3(0, 0, 1), step);
	tempx = ft_vector3_rotate_xy(ft_new_vector3(0, 0, 1), step);
	r->orient = ft_vector3_rotate_yx(
			ft_vector3_normalise(ft_matrix3_addition(tempx, tempy)), cam->rot);
}
