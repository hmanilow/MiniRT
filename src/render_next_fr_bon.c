/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_fr_bon.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:16:23 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:25 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bon.h"

static void	iterate_pixels(t_scene *scene, t_thread *thread)
{
	int		y;
	int		x;
	t_ray	*ray;

	y = thread->index * scene->everynframe;
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
		y = y + THREADS * scene->everynframe;
	}
}

void	*thread_loop(void *thread)
{
	while (1)
	{
		sem_wait(((t_bonus *)((t_thread *)thread)->scene->bonus)->threads1);
		sem_post(((t_bonus *)((t_thread *)thread)->scene->bonus)->threads2);
		iterate_pixels(((t_thread *)thread)->scene, thread);
		sem_wait(((t_bonus *)((t_thread *)thread)->scene->bonus)->threads3);
		sem_post(((t_bonus *)((t_thread *)thread)->scene->bonus)->threads4);
	}
	return (NULL);
}

static void	semaphores(t_bonus *bonus)
{
	int	i;

	i = 0;
	while (i++ < THREADS)
		sem_post(bonus->threads1);
	i = 0;
	while (i++ < THREADS)
		sem_wait(bonus->threads2);
	i = 0;
	while (i++ < THREADS)
		sem_post(bonus->threads3);
	i = 0;
	while (i++ < THREADS)
		sem_wait(bonus->threads4);
}

int	render_next_frame_bonus(t_scene *scene)
{
	ft_animate(scene);
	if (scene->idle < 0)
		return (0);
	((t_bonus *)scene->bonus)->timestamp = mtv();
	if (!scene->rays_set)
		ft_reset_rays(scene);
	semaphores(((t_bonus *)scene->bonus));
	ft_iterate_pixels_gamma_correction(scene);
	ft_update_window(scene);
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
