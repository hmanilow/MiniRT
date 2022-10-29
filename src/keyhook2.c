/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:14:41 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:09 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_change_fov(int keyhook, t_scene *scene)
{
	if (keyhook == KEY_OPENBRACKET && scene->view)
		scene->cam->fov -= 5;
	else if (keyhook == KEY_OPENBRACKET && !scene->view)
		scene->cam->zoom -= 5;
	else if (keyhook == KEY_CLOSEBRACKET && scene->view)
		scene->cam->fov += 5;
	else if (keyhook == KEY_CLOSEBRACKET && !scene->view)
		scene->cam->zoom += 5;
	else
		return (0);
	ft_redraw_frame(scene);
	return (1);
}

int	ft_change_maxquality(int keyhook, t_scene *scene)
{
	if (keyhook == KEY_1)
		scene->maxquality = 1;
	else if (keyhook == KEY_2)
		scene->maxquality = 2;
	else if (keyhook == KEY_3)
		scene->maxquality = 3;
	else if (keyhook == KEY_4)
		scene->maxquality = 4;
	else if (keyhook == KEY_5)
		scene->maxquality = 5;
	else
		return (0);
	if (scene->everynframe < scene->maxquality)
		scene->everynframe = scene->maxquality;
	scene->idle = 0;
	return (1);
}

int	ft_change_minquality(int keyhook, t_scene *scene)
{
	if (keyhook == KEY_6 && kd_max(scene->width, scene->height) >= 240)
		scene->minquality = kd_max(scene->width, scene->height) / 240;
	else if (keyhook == KEY_7 && kd_max(scene->width, scene->height) >= 120)
		scene->minquality = kd_max(scene->width, scene->height) / 120;
	else if (keyhook == KEY_8 && kd_max(scene->width, scene->height) >= 60)
		scene->minquality = kd_max(scene->width, scene->height) / 60;
	else if (keyhook == KEY_9 && kd_max(scene->width, scene->height) >= 40)
		scene->minquality = kd_max(scene->width, scene->height) / 40;
	else if (keyhook == KEY_0 && kd_max(scene->width, scene->height) >= 20)
		scene->minquality = kd_max(scene->width, scene->height) / 20;
	else if (keyhook == KEY_6 || keyhook == KEY_7 || keyhook == KEY_8
		|| keyhook == KEY_9 || keyhook == KEY_0)
		scene->minquality = 1;
	else
		return (0);
	scene->idle = 0;
	return (1);
}

int	ft_toggle_flags(int keyhook, t_scene *scene)
{
	if (keyhook == KEY_Z)
		ft_toggle(&scene->no_shadows);
	else if (keyhook == KEY_X)
		ft_toggle(&scene->one_light);
	else if (keyhook == KEY_C)
		ft_toggle(&scene->no_lights);
	else if (keyhook == KEY_V)
		ft_toggle(&scene->no_specular);
	else if (keyhook == KEY_B)
		ft_toggle(&scene->checkerboard);
	else if (keyhook == KEY_N)
		ft_toggle(&scene->bump);
	else if (keyhook == KEY_M)
		ft_toggle(&scene->gamma_correction);
	else
		return (0);
	if (keyhook == KEY_M)
		scene->idle = 0;
	else
		ft_redraw_frame(scene);
	return (1);
}

int	ft_move_light(int keyhook, t_scene *scene)
{
	if (!scene->light)
		return (0);
	if (keyhook == KEY_SPACE)
	{
		scene->cur_light = scene->cur_light->next;
		if (!scene->cur_light)
			scene->cur_light = scene->light;
	}
	else if (keyhook == KEY_I)
		scene->cur_light->pos.z += 5;
	else if (keyhook == KEY_J)
		scene->cur_light->pos.x -= 5;
	else if (keyhook == KEY_K)
		scene->cur_light->pos.z -= 5;
	else if (keyhook == KEY_L)
		scene->cur_light->pos.x += 5;
	else if (keyhook == KEY_U)
		scene->cur_light->pos.y -= 5;
	else if (keyhook == KEY_O)
		scene->cur_light->pos.y += 5;
	else
		return (0);
	if (!(keyhook == KEY_SPACE && !scene->one_light))
		ft_redraw_frame(scene);
	return (1);
}
