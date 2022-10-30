/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:17:07 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:34 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_mlx_window_init(t_scene *scene)
{
	scene->width = WINDOW_WIDTH;
	scene->height = WINDOW_HEIGHT;
	scene->mlx = mlx_init();
	if (scene->mlx == NULL)
		ft_error(-1);
	scene->window = mlx_new_window(scene->mlx, scene->width, scene->height, WN);
	if (scene->window == NULL)
		ft_error(-1);
	scene->img = ft_new_image(NULL, WINDOW_WIDTH, WINDOW_HEIGHT, scene);
	scene->img2 = ft_new_image(NULL, WINDOW_WIDTH, WINDOW_HEIGHT, scene);
}

void	ft_parse_line(t_scene *scene, char *s)
{
	while (ft_isspace(*s))
		s++;
	if (s[0] == '\0'
		|| (BONUS && (s[0] == '#' || (s[0] == '/' && s[1] == '/'))))
		;
	else if (s[0] == 's' && s[1] == 'p')
		ft_add_sphere(scene, &s[2]);
	else if (s[0] == 'p' && s[1] == 'l')
		ft_add_plane(scene, &s[2]);
	else if (s[0] == 'c' && s[1] == 'y')
		ft_add_cylinder(scene, &s[2]);
	else if (s[0] == 'c' && s[1] == 'n')
		ft_add_cone(scene, &s[2]);
	else if (s[0] == 'C')
		ft_add_camera(scene, &s[1]);
	else if (s[0] == 'A')
		ft_add_ambient(scene, &s[1]);
	else if (s[0] == 'L')
		ft_ft_add_light(scene, &s[1]);
	else
		ft_error(5);
}

void	ft_scene_init(char *fn, t_scene *scene)
{
	char	*s;
	int		fd;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		ft_error(2);
	s = kd_malloc_add(get_next_line(fd));
	while (s)
	{
		ft_parse_line(scene, s);
		kd_free(s);
		s = kd_malloc_add(get_next_line(fd));
	}
	if (scene->cam == NULL)
		scene->cam = ft_new_camera(ft_new_vector3(0, 0, 0),
				ft_new_vector3(0, 0, 1), 70);
	close(fd);
}
