#ifndef MINIRT_42_MINIRTMAIN_H
#define MINIRT_42_MINIRTMAIN_H

# include "base.h"
#include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct  s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pix;
    int     line_len;
    int     endian;
}               t_img;

typedef struct  s_base
{
    void    *mlx;
    void    *window;
    t_img   *img;
    t_scene *scene;
}               t_base;

//parse
int	parse(int argc, char **argv, t_base *base);

//parse settigs
void		parse_resol(t_base *base, char **str);
void		parse_amb_light(t_base *base, char **str);
void		parse_light(t_base *base, char **str);
void		parse_cam(t_base *base, char **str);

//parse utils
int	str_to_int(char **s);
void	skip_space(char **s);

//rendering

// error handling
void	arg_error(char *sms);

#endif
