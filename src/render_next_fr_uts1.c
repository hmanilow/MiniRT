/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_fr_uts1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:16:28 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:31 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_raytrace(int x, int y, t_ray *r, t_scene *scene)
{
	t_vector2	step;

	step = ft_new_vector2((x - scene->width / (double) 2) / scene->width
			* (double) 2, -(y - scene->height / (double) 2) / scene->width
			* (double) 2);
	if (scene->view == 0)
		ft_ray_orthographic(scene->cam, step, r);
	if (scene->view == 1)
		ft_ray_perspective_tan(scene->cam, step, r);
	else if (scene->view == 2)
		ft_ray_perspective_spherise(scene->cam, step, r);
	else if (scene->view == 3)
		ft_ray_perspective_spherise2(scene->cam, step, r);
	else if (scene->view == 4)
		ft_ray_perspective_spherise3(scene->cam, step, r);
	else if (scene->view == 5)
		ft_ray_perspective_quaternion(scene, x, y, r);
	else if (scene->view == 6)
		ft_ray_perspective_quaternion2(scene, x, y, r);
	ft_intersect(r, scene);
}

void	ft_animate(t_scene *scene)
{
	if (scene->play)
	{
		scene->everynframe = scene->minquality;
		scene->idle = 0;
		scene->rays_set = FALSE;
		scene->gamma = 1;
		if (scene->play == 3)
		{
			ft_rotate_camera_xz(scene->cam, -10);
			ft_rotate_camera_y(scene->cam, 10);
		}
		else if (scene->play == 2)
			ft_rotate_camera_xz(scene->cam, -10);
		else if (scene->play == 1)
			ft_rotate_camera_y(scene->cam, 10);
		else
			scene->play = 0;
	}
}

void	ft_update_window(t_scene *scene)
{
	if (!scene->oddframe)
	{
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img->image,
			0, 0);
		scene->oddframe = 1;
	}
	else
	{
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img2->image,
			0, 0);
		scene->oddframe = 0;
	}
	ft_hud(scene);
}

void	ft_iterate_pixels_gamma_correction(t_scene *scene)
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
				ft_draw_pixel(scene, x, y,
					ft_colour_gamma_apply(ray->color, scene));
			x++;
		}
		y++;
	}
}

void	ft_reset_rays(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->width * scene->height)
		scene->rays[i++].t = 0;
	scene->rays_set = TRUE;
}
