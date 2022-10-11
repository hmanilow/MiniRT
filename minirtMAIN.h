#ifndef MINIRT_42_MINIRTMAIN_H
#define MINIRT_42_MINIRTMAIN_H

#include "sources/utils/utils.h"
#include "sources/parser/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>
#include <sys/fcntl.h>
#include <errno.h>

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
    t_list      *camera;
    t_list      *light;
    t_list      *sphere;
    t_list      *plane;
    t_list      *cylinder;
}               t_scene;

t_scene *parse(int fd);

t_scene *fd_openning(const int argc, char **argv);

void print_error(const char *str, const int error);
int ft_strncmp_reverse(char *argv, char *str, int a);

#endif
