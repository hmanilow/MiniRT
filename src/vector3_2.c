/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:17:43 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:37 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	ft_vector3_multiply(t_vector3 direc, double multiply)
{
	direc.x *= multiply;
	direc.y *= multiply;
	direc.z *= multiply;
	return (direc);
}

double	ft_vector3_sumpow2(t_vector3 a)
{
	return (pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}

double	ft_vector3_scalar(t_vector3 a, t_vector3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector3	ft_vector3_qrotate(t_vector3 a, double theta, t_vector3 axis)
{
	t_vector3		b;
	t_quaternion	q;

	theta = M_PI / 180 * theta;
	q = ft_new_quaternion(theta, axis);
	b.x = a.x * (1 - 2 * (pow(q.j, 2) + pow(q.k, 2))) + a.y * (2 * (q.i * q.j
				- q.k * q.w)) + a.z * (2 * (q.i * q.k + q.j * q.w));
	b.y = a.x * (2 * (q.i * q.j + q.k * q.w)) + a.y * (1 - 2 * (pow(q.i, 2)
				+ pow(q.k, 2))) + a.z * (2 * (q.j * q.k - q.i * q.w));
	b.z = a.x * (2 * (q.i * q.k - q.j * q.w)) + a.y * (2 * (q.j * q.k + q.i
				* q.w)) + a.z * (1 - 2 * (pow(q.i, 2) + pow(q.j, 2)));
	return (b);
}
