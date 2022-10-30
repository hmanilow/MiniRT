/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtv_bon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:49 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:19 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "minirt_bon.h"

long	mtv(void)
{
	struct timeval	tv;
	static long		start;

	gettimeofday(&tv, NULL);
	if (!start)
	{
		start = (long) tv.tv_sec * 1000 + tv.tv_usec / 1000;
		return (0);
	}
	return (((long)tv.tv_sec * 1000 + tv.tv_usec / 1000) - start);
}
