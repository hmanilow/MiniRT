/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:14:47 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:10 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	*ft_clean_shapes(void *shape, void *next)
{
	kd_free(shape);
	return (next);
}

void	ft_next_scene(t_scene *scene)
{
	scene->light = kd_free(scene->light);
	scene->amb = kd_free(scene->amb);
	scene->cam = kd_free(scene->cam);
	while (scene->sph)
		scene->sph = ft_clean_shapes(scene->sph, scene->sph->next);
	while (scene->planes)
		scene->planes = ft_clean_shapes(scene->planes, scene->planes->next);
	while (scene->cy)
		scene->cy = ft_clean_shapes(scene->cy,
				scene->cy->next);
	while (scene->cones)
		scene->cones = ft_clean_shapes(scene->cones, scene->cones->next);
	if (!scene->maps[++scene->map_index])
	{
		printf("Last scene\n");
		scene->map_index = 0;
	}
	printf("Scene: %s\n", scene->maps[scene->map_index]);
	ft_scene_init(scene->maps[scene->map_index], scene);
	ft_redraw_frame(scene);
}
