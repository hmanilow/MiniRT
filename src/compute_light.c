/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:12:29 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:18:54 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	ft_compute_shadow(t_light *light, t_vector3 l, t_ray *ray,
								t_scene *scene)
{
	t_ray	newray;

	newray.pos = ray->coordinates;
	newray.orient = l;
	newray.t = INFINITY;
	ft_intersect(&newray, scene);
	if (newray.t > EPSILON && pow(newray.t, 2) + EPSILON < ft_vector3_sumpow2(
			ft_matrix3_subtract(light->pos, ray->coordinates)))
		return (TRUE);
	return (FALSE);
}

static t_color	ft_apply_light(t_color obj, t_color light, double intensity)
{
	return (ft_colour_matrix_amplify(obj, ft_col_amplify(light, intensity)));
}

static void	ft_process_light(t_cl *cl, t_ray *ray, t_scene *scene)
{
	cl->l = ft_vector3_normalise(
			ft_matrix3_subtract(cl->light->pos, ray->coordinates));
	cl->fctr = ft_vector3_scalar(ray->normal, cl->l);
	if (cl->fctr < 0 || (!scene->no_shadows
			&& ft_compute_shadow(cl->light, cl->l, ray, scene)))
		cl->fctr = 0;
	cl->color = ft_col_add(cl->color, ft_col_amplify(ft_apply_light(
					ray->color, cl->light->color, cl->light->bright),
				cl->fctr));
	if (!scene->no_specular && cl->fctr)
	{
		cl->h = ft_vector3_normalise(ft_matrix3_addition(
					ft_vector3_negate(ray->orient), cl->l));
		cl->n = 16;
		cl->hf = ft_vector3_scalar(cl->h, ray->normal) * sin(M_PI_2
				* sin(M_PI_2 * sin(M_PI_2 * sin(M_PI_2 * cl->fctr))));
		if (cl->hf > 0)
			cl->color = ft_col_add(cl->color, ft_col_amplify(ft_apply_light(
							cl->color, cl->light->color,
							cl->light->bright), pow(cl->hf, cl->n)));
	}
}

//блики
//перпендикулярный нормаль к свету = 0, параллельный = 1
void	ft_compute_light(t_ray *ray, t_scene *scene)
{
	t_cl	cl;

	if (ray->t == INFINITY)
	{
		ray->color = ft_new_color(DEF_BG_COLOR_R,
				DEF_BG_COLOR_G, DEF_BG_COLOR_B);
		return ;
	}
	if (scene->amb)
		cl.color = ft_apply_light(ray->color, scene->amb->color,
				scene->amb->bright);
	else
		cl.color = ft_new_color(0, 0, 0);
	cl.light = scene->light;
	while (cl.light && !scene->no_lights)
	{
		if (!scene->one_light || scene->cur_light == cl.light)
		{
			ft_process_light(&cl, ray, scene);
		}
		cl.light = cl.light->next;
	}
	ray->color = ft_colour_gamma_collect(cl.color, scene);
}
