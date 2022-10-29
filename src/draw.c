/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:13:04 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:01 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_color_to_int(t_color col)
{
	return (col.r << 16 | col.g << 8 | col.b);
}

void	ft_draw_pixel(t_scene *scene, int x, int y, t_color col)
{
	char	*dst;
	t_img	*img;
	int		i;
	int		j;

	if (!scene->oddframe)
		img = scene->img;
	else
		img = scene->img2;
	i = 0;
	while (i < scene->everynframe && y + i < scene->height)
	{
		j = 0;
		while (j < scene->everynframe && x + j < scene->width)
		{
			dst = img->addr + ((y + i) * img->bytes_per_line + (x + j)
					* (img->bits_per_pixel / 8));
			*(unsigned int *)dst = ft_color_to_int(col);
			j++;
		}
		i++;
	}
}
