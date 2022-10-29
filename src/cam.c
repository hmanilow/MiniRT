/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:11:54 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:18:41 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_direction_limits(t_vector3 orient, int *error)
{
	if (orient.x < -1 || orient.x > 1)
		*error = 1;
	if (orient.y < -1 || orient.y > 1)
		*error = 1;
	if (orient.z < -1 || orient.z > 1)
		*error = 1;
}

void	ft_add_camera(t_scene *scene, char *s)
{
	t_vector3	origin;
	t_vector3	direction;
	double		fov;
	int			err;

	if (scene->cam != NULL)
		ft_error(4);
	err = 0;
	origin = ft_new_vector_atof(&s, &err);
	direction = ft_new_vector_atof(&s, &err);
	ft_check_direction_limits(direction, &err);
	fov = ft_atof(&s, &err);
	if (fov < 0 || fov > 180)
		err = 1;
	ft_check_endline(&s, &err);
	if (err)
		ft_error(4);
	scene->cam = ft_new_camera(origin, direction, fov);
	scene->cam->defaults = ft_new_camera(origin, direction, fov);
}

void	ft_reset_camera(t_scene *scene)
{
	scene->cam->pos = scene->cam->defaults->pos;
	scene->cam->orient = scene->cam->defaults->orient;
	scene->cam->rot = scene->cam->defaults->rot;
	scene->cam->fov = scene->cam->defaults->fov;
	scene->cam->zoom = scene->cam->defaults->zoom;
	ft_redraw_frame(scene);
}

t_camera	*ft_new_camera(t_vector3 pos, t_vector3 orient, double fov)
{
	t_camera	*camera;

	camera = kd_calloc(1, sizeof(t_camera));
	if (camera == NULL)
		ft_error(-1);
	camera->pos = pos;
	camera->orient = ft_new_vector3(0, 0, 1);
	camera->rot = ft_vector3_arotate(ft_vector3_normalise(
				orient), camera->orient);
	camera->rot_origin = pos;
	camera->fov = fov;
	camera->zoom = DEFAULT_ZOOM;
	return (camera);
}
