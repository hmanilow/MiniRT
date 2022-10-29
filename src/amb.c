/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:11:44 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:18:39 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_ratio_limits(double bright, int *error)
{
	if (bright < 0 || bright > 1)
		*error = 1;
}

void	ft_add_ambient(t_scene *scene, char *s)
{
	double	bright;
	t_color	col;
	int		err;

	if (scene->amb != NULL)
		ft_error(6);
	err = 0;
	bright = ft_atof(&s, &err);
	ft_check_ratio_limits(bright, &err);
	col = ft_new_color_atoc(&s, &err);
	ft_check_endline(&s, &err);
	if (err)
		ft_error(6);
	scene->amb = ft_new_ambient(bright, col);
}

t_ambient	*ft_new_ambient(double bright, t_color color)
{
	t_ambient	*amb;

	amb = kd_calloc(1, sizeof(t_ambient));
	if (amb == NULL)
		ft_error(-1);
	amb->bright = bright;
	amb->color = color;
	return (amb);
}
