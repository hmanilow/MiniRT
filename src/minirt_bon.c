/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:10 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:14 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "minirt_bon.h"

static void	vars_init(t_scene *scene)
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

static void	semaphores_init(t_scene *scene)
{
	t_bonus	*bonus;

	scene->bonus = kd_calloc(1, sizeof(t_bonus));
	bonus = scene->bonus;
	sem_unlink("threads1");
	bonus->threads1 = sem_open("threads1", O_CREAT | O_EXCL, 0660, 0);
	sem_unlink("threads1");
	sem_unlink("threads2");
	bonus->threads2 = sem_open("threads2", O_CREAT | O_EXCL, 0660, 0);
	sem_unlink("threads2");
	sem_unlink("threads3");
	bonus->threads3 = sem_open("threads3", O_CREAT | O_EXCL, 0660, 0);
	sem_unlink("threads3");
	sem_unlink("threads4");
	bonus->threads4 = sem_open("threads4", O_CREAT | O_EXCL, 0660, 0);
	sem_unlink("threads4");
}

static void	threads_init(t_scene *scene)
{
	int			i;
	t_thread	*thread;

	thread = kd_calloc(THREADS, sizeof(t_thread));
	i = 0;
	while (i < THREADS)
	{
		thread[i].index = i;
		thread[i].scene = scene;
		pthread_create(&(thread[i].thread), NULL, thread_loop, &thread[i]);
		pthread_detach(thread[i].thread);
		i++;
	}
	printf("Started %d threads\n", THREADS);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc == 1 || ft_invalid_filename(argv[1]))
		ft_error(1);
	scene = (t_scene *)kd_calloc(1, sizeof(t_scene));
	if (scene == NULL)
		ft_error(-1);
	scene->maps = &argv[1];
	ft_scene_init(*scene->maps, scene);
	ft_mlx_window_init(scene);
	vars_init(scene);
	semaphores_init(scene);
	threads_init(scene);
	mlx_loop_hook(scene->mlx, render_next_frame_bonus, scene);
	mlx_hook(scene->window, 2, (1L << 0), ft_key_hook, scene);
	mlx_hook(scene->window, 17, 0, ft_close_minirt, scene);
	mlx_mouse_hook(scene->window, ft_mouse_hook, scene);
	mlx_loop(scene->mlx);
}
