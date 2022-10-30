/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:17:48 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:38 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	ft_vector3_rotate_yx(t_vector3 a, t_vector2 rot)
{
	t_vector3	b;

	rot.v = M_PI / 180 * -rot.v;
	b.x = a.x;
	b.y = a.y * cos(rot.v) - a.z * sin(rot.v);
	b.z = a.y * sin(rot.v) + a.z * cos(rot.v);
	rot.u = M_PI / 180 * -rot.u;
	a.x = b.x * cos(rot.u) - b.z * sin(rot.u);
	a.y = b.y;
	a.z = b.x * sin(rot.u) + b.z * cos(rot.u);
	return (a);
}

t_vector3	ft_vector3_rotate_xy(t_vector3 b, t_vector2 rot)
{
	t_vector3	a;

	rot.u = M_PI / 180 * -rot.u;
	a.x = b.x * cos(rot.u) - b.z * sin(rot.u);
	a.y = b.y;
	a.z = b.x * sin(rot.u) + b.z * cos(rot.u);
	rot.v = M_PI / 180 * -rot.v;
	b.x = a.x;
	b.y = a.y * cos(rot.v) - a.z * sin(rot.v);
	b.z = a.y * sin(rot.v) + a.z * cos(rot.v);
	return (b);
}

t_vector2	ft_vector3_arotate(t_vector3 a, t_vector3 b)
{
	t_vector2	c;
	t_vector2	r;

	c.u = 0;
	c.v = 0;
	r.v = -90;
	while (r.v <= 90)
	{
		r.u = 0;
		while (r.u < 360)
		{
			if (ft_vector3_scalar(a, ft_vector3_rotate_yx(b, r))
				> ft_vector3_scalar(a, ft_vector3_rotate_yx(b, c)))
				c = r;
			r.u++;
		}
		r.v++;
	}
	return (c);
}

t_vector3	ft_new_vector3(double x, double y, double z)
{
	t_vector3	a;

	a.z = z;
	a.x = x;
	a.y = y;
	return (a);
}
