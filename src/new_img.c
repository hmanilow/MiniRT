/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:56 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:20 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img	*ft_new_image(char *path, int w, int h, t_scene *scene)
{
	t_img	*image;

	image = kd_calloc(1, sizeof(t_img));
	if (!image)
		ft_error(-1);
	if (path)
		image->image = mlx_xpm_file_to_image(scene->mlx, path,
				&image->width, &image->height);
	else
		image->image = mlx_new_image(scene->mlx, w, h);
	if (!image->image)
		ft_error(-1);
	image->addr = mlx_get_data_addr(image->image, &image->bits_per_pixel,
			&image->bytes_per_line, &image->endian);
	if (!image->addr)
		ft_error(-1);
	return (image);
}
