/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:19 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:16 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_vars_init(t_scene *scene)
{
	scene->view = 5;
	scene->gamma = 1;
	scene->maxquality = 1;
	scene->minquality = kd_max(scene->width, scene->height) / 20;
	scene->everynframe = scene->minquality;
	scene->bumpmap = ft_new_image("sprites/plane_bump_map.xpm", 0, 0, scene);
	scene->texturemap = ft_new_image("sprites/textureground.xpm", 0, 0, scene);
	scene->rays = kd_calloc(scene->width * scene->height, sizeof(t_ray));
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc == 1 || ft_invalid_filename(argv[1]))
		ft_error(1);
	scene = (t_scene *) kd_calloc(1, sizeof(t_scene));
	if (scene == NULL)
		ft_error(-1);
	scene->maps = &argv[1];
	ft_scene_init(*scene->maps, scene);
	ft_mlx_window_init(scene);
	ft_vars_init(scene);
	mlx_loop_hook(scene->mlx, ft_render_next_frame, scene);
	mlx_hook(scene->window, 2, (1L << 0), ft_key_hook, scene);
	mlx_hook(scene->window, 17, 0, ft_close_minirt, scene);
	mlx_mouse_hook(scene->window, ft_mouse_hook, scene);
	mlx_loop(scene->mlx);
}
