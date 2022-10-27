#include "../../inc/minirtMAIN.h"

void	parse_resol(t_base *base, char **str)
{
    skip_space(str);
    base->scene->resolution[0] = str_to_int(str);
    check_range(base->scene->resolution[0], 1, INFINITY, "RESOLUTION");
    base->scene->resolution[1] = str_to_int(str);
    check_range(base->scene->resolution[1], 1, INFINITY, "RESOLUTION");
    init_mlx(base);
}

void	parse_amb_light(t_base *base, char **str)
{
    skip_space(str);
    base->scene->a_light = str_to_double(str);
    check_range(minirt->scene->a_light, 0.0, 1.0, "AMBIENT LIGHT");
    base->scene->al_color = parse_color(str);
}

void	parse_light(t_base *base, char **str)
{
    skip_space(str);
    base->scene->light->coord = parse_point3(str);
    base->scene->light->bri = str_to_double(str);
    check_range(base->scene->light->bri, 0.0, 1.0, "LIGHT");
    base->scene->light->color = parse_color(str);
}

void	parse_cam(t_base *base, char **str)
{
    skip_space(str);
    base->scene->camera->pos = parse_point3(str);
    base->scene->camera->no_vec = normalize(parse_point3(str));
    skip_space(str);
    base->scene->camera->deg = str_to_int(str);
    check_range(base->scene->camera->deg, 0.0, 180.0, "CAMERA");
}

//parsing param
