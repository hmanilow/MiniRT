/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:16:12 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:23 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*ft_texture_plane_get_addr(t_img *image, t_vector2 tile)
{
	return (image->addr + ((int)fmod(fmod(tile.v, image->height)
				+ image->height, image->height)
			* image->bytes_per_line + (int)fmod(fmod(tile.u, image->width)
				+ image->width, image->width) * (image->bits_per_pixel / 8)));
}

void	ft_texture_plane(t_plane *p, t_ray *ray, t_bool bump, t_scene *scene)
{
	t_pl		pl;

	if (!bump)
		return ;
	pl.local = ft_matrix3_subtract(ray->coordinates, p->pos);
	pl.ulocal = ft_vector3_normalise(pl.local);
	pl.costheta = ft_vector3_scalar(pl.ulocal, ft_vector3_cw(p->orient));
	pl.tile.u = sqrt(ft_vector3_sumpow2(pl.local)) * pl.costheta * 100;
	pl.costheta = ft_vector3_scalar(pl.ulocal, ft_vector3_ccw(p->orient));
	pl.tile.v = sqrt(ft_vector3_sumpow2(pl.local)) * pl.costheta * 100;
	pl.dst = ft_texture_plane_get_addr(scene->texturemap, pl.tile);
	ray->color = ft_new_color((*(unsigned int *) pl.dst & 0x00ff0000) >> 16,
			(*(unsigned int *) pl.dst & 0x0000ff00) >> 8,
			(*(unsigned int *) pl.dst & 0x000000ff));
	pl.dst = ft_texture_plane_get_addr(scene->bumpmap, pl.tile);
	pl.color = ft_new_vector3((*(unsigned int *) pl.dst & 0x00ff0000) >> 16,
			(*(unsigned int *) pl.dst & 0x0000ff00) >> 8,
			(*(unsigned int *) pl.dst & 0x000000ff));
	pl.color.x = (pl.color.x / 255 - 0.5) * 2;
	pl.color.y = (pl.color.y / 255 - 0.5) * 2;
	pl.color.z = (pl.color.z / 255 - 0.5) * 2;
	ray->normal = ft_vector3_qrotate(ft_vector3_qrotate(ray->normal, pl.color.y
				* 90, ft_vector3_cw(p->orient)), pl.color.x * -90,
			ft_vector3_ccw(p->orient));
}
