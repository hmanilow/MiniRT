#ifndef MINIRT_42_PARSE_H
#define MINIRT_42_PARSE_H

#include "../../minirtMAIN.h"

typedef struct s_point
{
    double	x;
    double	y;
    double	z;
}	t_point;

typedef struct s_camera
{
    t_point	position;
    t_point	vector;
    double	fov;
}	t_camera;

typedef struct  s_light
{
    t_point	position;
    double	ratio;
    int		color;
}               t_light;

typedef struct  s_sphere
{
    t_point			center;
    double			rad;
}               t_sphere;

typedef struct  s_plane
{
    t_point position;
    t_point vector;
}               t_plane;

typedef struct  s_cylinder
{
    t_point			position;
    t_point			vector;
    double			radius;
    double			height;
}               t_cylinder;

typedef struct  s_rgb
{
    int r;
    int g;
    int b;
}               t_rgb;

typedef struct  s_amb_light
{
    double  ratio;
    t_rgb   rgb;
}               t_amb_light;

typedef struct  s_scene //+resol
{
    t_amb_light Amb_lig;
    t_camera    *camera;
    t_light     *light;
    t_sphere    *sphere;
    t_plane     *plane;
    t_cylinder  *cylinder;
}               t_scene;


//int parse();
//int fd_openning();

#endif
