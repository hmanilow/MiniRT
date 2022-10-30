/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_fr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:17:00 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:33 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_iterate_pixels(t_scene *scene)
{
	int		y;
	int		x;
	t_ray	*ray;

	y = 0;
	while (y < scene->height)
	{
		x = 0;
		while (x < scene->width)
		{
			ray = &scene->rays[y * scene->width + x];
			if (x % scene->everynframe == 0
				&& y % scene->everynframe == 0)
			{
				if (!ray->t)
				{
					ray->t = INFINITY;
					ft_raytrace(x, y, ray, scene);
					ft_compute_light(ray, scene);
				}
			}
			x++;
		}
		y++;
	}
}

int	ft_render_next_frame(t_scene *scene)
{
	ft_animate(scene);
	if (scene->idle > 0)
	{
		scene->idle--;
		return (0);
	}
	else if (scene->idle < 0)
		return (0);
	if (!scene->rays_set)
		ft_reset_rays(scene);
	ft_iterate_pixels(scene);
	ft_iterate_pixels_gamma_correction(scene);
	ft_update_window(scene);
	scene->idle = 1;
	if (scene->everynframe >= 20)
		scene->everynframe /= 2;
	else if (scene->everynframe > 10)
		scene->everynframe = 10;
	else if (scene->everynframe > scene->maxquality)
		scene->everynframe--;
	else
		scene->idle = -1;
	return (0);
}
