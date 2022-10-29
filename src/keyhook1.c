/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:14:34 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:08 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_redraw_frame(t_scene *scene)
{
	scene->everynframe = scene->minquality;
	scene->rays_set = FALSE;
	scene->idle = 0;
	scene->gamma = 1;
}

void	ft_rotate_camera_xz(t_camera *camera, int theta)
{
	t_vector2	rotate;
	t_vector3	axis;

	rotate.u = camera->rot.u - 90;
	rotate.v = 0;
	axis = ft_vector3_rotate_yx(camera->orient, rotate);
	camera->pos = ft_matrix3_addition(camera->rot_origin, ft_vector3_qrotate(
				ft_matrix3_subtract(camera->pos, camera->rot_origin),
				theta, axis));
	camera->rot.v += theta;
}

void	ft_rotate_camera_y(t_camera *camera, int theta)
{
	t_vector3	axis;

	axis = ft_new_vector3(0, 1, 0);
	camera->pos = ft_matrix3_addition(camera->rot_origin, ft_vector3_qrotate(
				ft_matrix3_subtract(camera->pos, camera->rot_origin),
				theta, axis));
	camera->rot.u += theta;
}

int	ft_rotate_camera(int keyhook, t_scene *scene)
{
	if (keyhook == KEY_UP)
		ft_rotate_camera_xz(scene->cam, 5);
	else if (keyhook == KEY_DOWN)
		ft_rotate_camera_xz(scene->cam, -5);
	else if (keyhook == KEY_LEFT)
		ft_rotate_camera_y(scene->cam, -5);
	else if (keyhook == KEY_RIGHT)
		ft_rotate_camera_y(scene->cam, 5);
	else
		return (0);
	ft_redraw_frame(scene);
	return (1);
}

//	printf("keyhook %d\n", keyhook);
int	ft_key_hook(int keyhook, t_scene *scene)
{
	if (keyhook == KEY_ESC)
		ft_close_minirt();
	else if (keyhook == KEY_R)
	{
		scene->view++;
		if (scene->view >= 7 || scene->view < 0)
			scene->view = 0;
		ft_redraw_frame(scene);
	}
	else if (keyhook == KEY_ENTER)
		scene->play++;
	else if (keyhook == KEY_F)
		ft_reset_camera(scene);
	else if (keyhook == KEY_TAB)
		ft_next_scene(scene);
	else if (ft_change_fov(keyhook, scene) || ft_rotate_camera(keyhook, scene)
		|| ft_move_camera(keyhook, scene)
		|| ft_change_maxquality(keyhook, scene)
		|| ft_change_minquality(keyhook, scene)
		|| ft_toggle_flags(keyhook, scene)
		|| ft_move_light(keyhook, scene))
		;
	return (0);
}
