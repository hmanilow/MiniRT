/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bon.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:15 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:15 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BON_H
# define MINIRT_BON_H

# include <pthread.h>
# include <semaphore.h>
# include "minirt.h"

# define THREADS 8

typedef struct s_thread
{
	pthread_t	thread;
	int			index;
	t_scene		*scene;
}	t_thread;

typedef struct s_bonus
{
	long		timestamp;
	sem_t		*threads1;
	sem_t		*threads2;
	sem_t		*threads3;
	sem_t		*threads4;
}	t_bonus;

int		render_next_frame_bonus(t_scene *scene);
void	*thread_loop(void *thread_void);
long	mtv(void);

#endif