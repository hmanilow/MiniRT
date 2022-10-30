/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:17:53 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:39 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector2	ft_new_vector2(double u, double v)
{
	t_vector2	a;

	a.u = u;
	a.v = v;
	return (a);
}

t_vector3	ft_vector3_negate(t_vector3 a)
{
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;
	return (a);
}

t_vector3	ft_vector3_cw(t_vector3 a)
{
	double	tmp;

	tmp = a.x;
	a.x = a.y;
	a.y = a.z;
	a.z = tmp;
	return (a);
}

t_vector3	ft_vector3_ccw(t_vector3 a)
{
	double	tmp;

	tmp = a.z;
	a.z = a.y;
	a.y = a.x;
	a.x = tmp;
	return (a);
}
