/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:13:09 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:02 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_invalid_filename(char *fn)
{
	int	len;

	len = ft_strlen(fn);
	if (len < 3 || fn[len - 1] != 't'
		|| fn[len - 2] != 'r' || fn[len - 3] != '.')
		return (1);
	return (0);
}

void	ft_error(int err)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (err == -1)
		ft_putstr_fd("Malloc error!\n", STDERR_FILENO);
	else if (err == 1)
		ft_putstr_fd("Error with filename argument\n", STDERR_FILENO);
	else if (err == 2)
		ft_putstr_fd("Opening error\n", STDERR_FILENO);
	else if (err == 3)
		ft_putstr_fd("Sphere error\n", STDERR_FILENO);
	else if (err == 4)
		ft_putstr_fd("Camera error\n", STDERR_FILENO);
	else if (err == 5)
		ft_putstr_fd("Wrong type identifier\n", STDERR_FILENO);
	else if (err == 6)
		ft_putstr_fd("Amb light error\n", STDERR_FILENO);
	else if (err == 7)
		ft_putstr_fd("Light error\n", STDERR_FILENO);
	else if (err == 8)
		ft_putstr_fd("Plane error\n", STDERR_FILENO);
	else if (err == 9)
		ft_putstr_fd("Cylinder error\n", STDERR_FILENO);
	else if (err == 10)
		ft_putstr_fd("Color error\n",
			STDERR_FILENO);
	ft_exit(err);
}
