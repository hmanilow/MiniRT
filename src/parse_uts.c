/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:16:01 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:20 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	ft_new_vector_atof(char **s, int *error)
{
	double	x;
	double	y;
	double	z;

	x = ft_atof(s, error);
	while (ft_isspace(**s))
		(*s)++;
	if (**s == ',')
		(*s)++;
	y = ft_atof(s, error);
	while (ft_isspace(**s))
		(*s)++;
	if (**s == ',')
		(*s)++;
	z = ft_atof(s, error);
	return (ft_new_vector3(x, y, z));
}
