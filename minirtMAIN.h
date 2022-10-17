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

# define PARSE_ERROR        -3
# define MLX_ERROR          -4
# define MALLOC_ERROR       -5

# define WINDOW_SIZE		1080

typedef struct  s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}               t_mlx;

typedef struct  s_img
{
    void            *img_ptr;
    int		        bits_per_pixel;
    int		        size_line;
    int		        endian;
    unsigned char	*data;
}					t_img;

typedef struct	s_window
{
    t_mlx		*mlx;
    t_img		*img;
    t_scene		*scene;
}				t_window;


t_scene *parse(int fd);

t_scene *fd_openning(const int argc, char **argv);

void print_error(const char *str, const int error);
int ft_strncmp_reverse(char *argv, char *str, int a);

#endif
