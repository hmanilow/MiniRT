/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:17:37 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:37 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	ft_matrix3_subtract(t_vector3 a, t_vector3 b)
{
	t_vector3	differ;

	differ.x = a.x - b.x;
	differ.y = a.y - b.y;
	differ.z = a.z - b.z;
	return (differ);
}

t_vector3	ft_matrix3_addition(t_vector3 a, t_vector3 b)
{
	t_vector3	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	return (sum);
}

double	ft_vector3_distance(t_vector3 a, t_vector3 b)
{
	double		dist;
	t_vector3	differ;

	differ = ft_matrix3_subtract(a, b);
	dist = sqrt(ft_vector3_sumpow2(differ));
	return (dist);
}

t_vector3	ft_vector3_normalise(t_vector3 direc)
{
	double	magnitude;

	magnitude = ft_vector3_sumpow2(direc);
	if (magnitude == 1)
		return (direc);
	magnitude = sqrt(magnitude);
	if (magnitude > 0)
	{
		direc.x /= magnitude;
		direc.y /= magnitude;
		direc.z /= magnitude;
	}
	return (direc);
}
