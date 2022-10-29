/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_cammove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:14:30 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:08 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_move_camera_y(t_camera *cam, double dist)
{
	t_vector2	rot;

	rot.u = cam->rot.u;
	rot.v = cam->rot.v + 90;
	cam->pos = ft_matrix3_addition(cam->pos,
			ft_vector3_multiply(ft_vector3_rotate_yx(cam->orient, rot),
				dist));
}

static void	ft_move_camera_x(t_camera *cam, double dist)
{
	t_vector2	rot;

	rot.u = cam->rot.u + 90;
	rot.v = 0;
	cam->pos = ft_matrix3_addition(cam->pos,
			ft_vector3_multiply(ft_vector3_rotate_yx(cam->orient, rot),
				dist));
}

static void	ft_move_camera_z(t_camera *cam, double dist)
{
	t_vector2	rot;

	rot = cam->rot;
	cam->pos = ft_matrix3_addition(cam->pos,
			ft_vector3_multiply(ft_vector3_rotate_yx(cam->orient, rot),
				dist));
}

int	ft_move_camera(int keyhook, t_scene *scene)
{
	if (keyhook == KEY_W)
		ft_move_camera_z(scene->cam, 5);
	else if (keyhook == KEY_S)
		ft_move_camera_z(scene->cam, -5);
	else if (keyhook == KEY_A)
		ft_move_camera_x(scene->cam, -5);
	else if (keyhook == KEY_D)
		ft_move_camera_x(scene->cam, 5);
	else if (keyhook == KEY_Q)
		ft_move_camera_y(scene->cam, -5);
	else if (keyhook == KEY_E)
		ft_move_camera_y(scene->cam, 5);
	else
		return (0);
	scene->cam->rot_origin = scene->cam->pos;
	ft_redraw_frame(scene);
	return (1);
}
