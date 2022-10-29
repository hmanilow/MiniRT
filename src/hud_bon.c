/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:13:26 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:06 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "minirt_bon.h"

void	ft_hud(t_scene *scene)
{
	kd_free(scene->hud);
	scene->hud = kd_strjoin_free("quality ", kd_itoa(scene->everynframe), 2);
	scene->hud = kd_strjoin_free(scene->hud, "/", 1);
	scene->hud = kd_strjoin_free(scene->hud, kd_itoa(scene->minquality), 0);
	scene->hud = kd_strjoin_free(scene->hud, " view ", 1);
	scene->hud = kd_strjoin_free(scene->hud, kd_itoa(scene->view), 0);
	if (!scene->view)
	{
		scene->hud = kd_strjoin_free(scene->hud, " zoom ", 1);
		scene->hud = kd_strjoin_free(scene->hud,
				kd_itoa((int)scene->cam->zoom), 0);
	}
	else
	{
		scene->hud = kd_strjoin_free(scene->hud, " fov ", 1);
		scene->hud = kd_strjoin_free(scene->hud,
				kd_itoa((int)scene->cam->fov), 0);
	}
	scene->hud = kd_strjoin_free(scene->hud, " frame ", 1);
	scene->hud = kd_strjoin_free(scene->hud,
			kd_itoa((int)mtv() - (int)((t_bonus *)scene->bonus)->timestamp), 0);
	scene->hud = kd_strjoin_free(scene->hud, "ms", 1);
	mlx_string_put(scene->mlx, scene->window, 20, 30, 0xFFFF00, scene->hud);
}
