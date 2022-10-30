/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:38 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:18 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_mouse_hook_button1(t_scene *scene, t_ray *ray)
{
	scene->cam->rot_origin = scene->cam->pos;
	if (scene->view)
		scene->cam->rot = ft_vector3_arotate(ray->orient,
				scene->cam->orient);
	else if (ray->t < INFINITY)
		scene->cam->rot = ft_vector3_arotate(ft_vector3_normalise(
					ft_matrix3_subtract(ray->coordinates,
						scene->cam->pos)), scene->cam->orient);
	else
		scene->cam->rot = ft_vector3_arotate(ft_vector3_normalise(
					ft_matrix3_subtract(ft_matrix3_addition(
							ray->pos, ft_vector3_multiply(ray->orient,
								100)), scene->cam->pos)), scene->cam->orient);
	scene->everynframe = scene->minquality;
	scene->rays_set = FALSE;
	scene->idle = 0;
}

int	ft_mouse_hook(int butt, int x, int y, t_scene *scene)
{
	t_ray	ray;

	if (x < 0 || x >= scene->width || y < 0 || y >= scene->height)
		return (0);
	ray = scene->rays[y * scene->width + x];
	if (!ray.t)
	{
		ray.t = INFINITY;
		ft_raytrace(x, y, &ray, scene);
	}
	if (butt == 1)
		ft_mouse_hook_button1(scene, &ray);
	if (butt == 2)
	{
		if (ray.t < INFINITY)
			scene->cam->rot_origin = ray.coordinates;
		else
			scene->cam->rot_origin = scene->cam->pos;
	}
	return (0);
}
