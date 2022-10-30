/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:16:17 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:24 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_quaternion_sumpow2(t_quaternion q)
{
	return (pow(q.w, 2) + pow(q.i, 2) + pow(q.j, 2) + pow(q.k, 2));
}

t_quaternion	ft_quaternion_normalise(t_quaternion q)
{
	double	magnitude;

	magnitude = ft_quaternion_sumpow2(q);
	if (magnitude == 1)
		return (q);
	magnitude = sqrt(magnitude);
	if (magnitude > 0)
	{
		q.w /= magnitude;
		q.i /= magnitude;
		q.j /= magnitude;
		q.k /= magnitude;
	}
	return (q);
}

t_quaternion	ft_new_quaternion(double theta, t_vector3 axis)
{
	t_quaternion	q;
	double			st;

	theta /= 2;
	st = sin(theta);
	axis = ft_vector3_normalise(axis);
	q.w = cos(theta);
	q.i = axis.x * st;
	q.j = axis.y * st;
	q.k = axis.z * st;
	return (ft_quaternion_normalise(q));
}
