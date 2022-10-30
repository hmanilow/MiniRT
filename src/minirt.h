/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:26 by hmanilow          #+#    #+#             */
/*   Updated: 2022/10/28 19:19:17 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../mlx_static/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libkd/libkd.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# ifndef BONUS
#  define BONUS 0
# endif

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 1200
# define WN "miniRT window"
# define DEF_BG_COLOR_R 128
# define DEF_BG_COLOR_G 128
# define DEF_BG_COLOR_B 128
# define DEFAULT_ZOOM 32
# define EPSILON 1e-6

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

enum e_keycode
{
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_Q = 12,
	KEY_E = 14,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_C = 8,
	KEY_V = 9,
	KEY_B = 11,
	KEY_N = 45,
	KEY_M = 46,
	KEY_F = 3,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_U = 32,
	KEY_O = 31,
	KEY_CMD = 259,
	KEY_SHIFT = 257,
	KEY_SPACE = 49,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_R = 15,
	KEY_ESC = 53,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
	KEY_6 = 22,
	KEY_7 = 26,
	KEY_8 = 28,
	KEY_9 = 25,
	KEY_0 = 29,
	KEY_ENTER = 36,
	KEY_TAB = 48,
	KEY_OPENBRACKET = 33,
	KEY_CLOSEBRACKET = 30
}	t_keycode;

typedef struct s_vector2
{
	double		u;
	double		v;
}	t_vector2;

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

typedef struct s_quaternion
{
	double	w;
	double	i;
	double	j;
	double	k;
}	t_quaternion;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_camera
{
	t_vector3		pos;
	t_vector3		orient;
	t_vector2		rot;
	t_vector3		rot_origin;
	double			fov;
	double			zoom;
	struct s_camera	*defaults;
}	t_camera;

typedef struct s_ambient
{
	double	bright;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	t_vector3		pos;
	double			bright;
	t_color			color;
	struct s_light	*next;
}	t_light;

typedef struct s_plane
{
	t_vector3		pos;
	t_vector3		orient;
	t_color			color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_disc
{
	t_vector3		pos;
	t_vector3		orient;
	double			radius;
	t_color			color;
	struct s_plane	*next;
}	t_disc;

typedef struct s_sphere
{
	t_vector3		pos;
	double			radius;
	t_color			color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_cylinder
{
	t_vector3			pos;
	t_vector3			orient;
	double				radius;
	double				height;
	t_disc				cap_bot;
	t_disc				cap_top;
	t_color				color;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_cone
{
	t_vector3		pos;
	t_vector3		orient;
	double			radius;
	double			height;
	t_color			color;
	t_disc			cap;
	double			theta;
	double			costheta;
	double			pow2costheta;
	struct s_cone	*next;
}	t_cone;

typedef struct s_img
{
	void	*image;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		bytes_per_line;
	int		endian;
}	t_img;

typedef struct s_ray
{
	t_vector3	pos;
	t_vector3	orient;
	double		t;
	t_vector3	coordinates;
	t_vector3	normal;
	t_color		color;
}	t_ray;

typedef struct s_scene
{
	t_camera	*cam;
	t_ambient	*amb;
	t_light		*light;
	t_light		*cur_light;
	t_plane		*planes;
	t_sphere	*sph;
	t_cylinder	*cy;
	t_cone		*cones;
	int			width;
	int			height;
	void		*mlx;
	void		*window;
	t_img		*img;
	t_img		*img2;
	char		*hud;
	t_bool		no_shadows;
	t_bool		one_light;
	t_bool		no_lights;
	t_bool		no_specular;
	t_bool		checkerboard;
	t_bool		bump;
	t_bool		gamma_correction;
	int			oddframe;
	int			maxquality;
	int			minquality;
	int			everynframe;
	int			play;
	int			idle;
	int			view;
	double		gamma;
	t_ray		*rays;
	t_bool		rays_set;
	t_img		*bumpmap;
	t_img		*texturemap;
	char		**maps;
	int			map_index;
	void		*bonus;
}	t_scene;

//quadratic equation, d - discriminant, t1 t2 - roots
typedef struct s_quad {
	double		a;
	double		b;
	double		c;
	double		d;
	double		sqrt_d;
	double		t1;
	double		t2;
}	t_quad;

typedef struct s_cl {
	t_light		*light;
	t_vector3	l;
	double		fctr;
	t_color		color;
	double		hf;
	t_vector3	h;
	double		n;
}	t_cl;

typedef struct s_pl {
	char		*dst;
	t_vector3	local;
	t_vector3	ulocal;
	double		costheta;
	t_vector2	tile;
	t_vector3	color;
}	t_pl;

//libft.c
size_t			ft_strlen(const char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);

//libft2.c
int				ft_isspace(char c);
int				ft_isdigit(int c);
void			ft_check_endline(char **s, int *error);

//error_managment.c
void			ft_error(int er);
int				ft_invalid_filename(char *fn);

//parse_utils.c
t_vector3		ft_new_vector_atof(char **s, int *error);

//sp.c
void			ft_intersect_sphere(t_sphere *sp, t_ray *r, t_scene *scene);
void			ft_add_sphere(t_scene *scene, char *s);
t_sphere		*ft_new_sphere(t_vector3 pos, double radius, t_color col);

//plane.c
void			ft_add_plane(t_scene *scene, char *s);
t_plane			*ft_new_plane(t_vector3 pos, t_vector3 orient, t_color col);
void			ft_texture_plane(t_plane *p, t_ray *ray, t_bool bump,
					t_scene *scene);

//cylinder.c
t_cylinder		*new_cylinder(t_vector3 position, t_vector3 orient,
					double radius);
void			add_cylinder_props(t_cylinder *cylinder, char *s);
void			ft_add_cylinder(t_scene *scene, char *str);

//cylinder_raytrace.c
int				ft_is_in_cutted_cylinder(t_cylinder *cy, t_ray *ray,
					t_quad q);
void			ft_init_cylinder_q(t_cylinder *cy, t_ray	*ray, t_quad *q);
void			ft_intersect_cylinder(t_cylinder *cy, t_ray *ray,
					t_scene *scene);

//cam.c
t_camera		*ft_new_camera(t_vector3 pos, t_vector3 orient, double fov);
void			ft_add_camera(t_scene *scene, char *s);
void			ft_check_direction_limits(t_vector3 orient, int *error);
void			ft_reset_camera(t_scene *scene);

//amb.c
t_ambient		*ft_new_ambient(double bright, t_color color);
void			ft_add_ambient(t_scene *scene, char *s);
void			ft_check_ratio_limits(double bright, int *error);

//light.c
t_light			*ft_new_light(t_vector3 pos, double bright, t_color col);
void			ft_ft_add_light(t_scene *scene, char *s);

//ft_scene_init.c
void			ft_mlx_window_init(t_scene *scene);
void			ft_scene_init(char *fn, t_scene *scene);

//draw.c
void			ft_draw_pixel(t_scene *scene, int x, int y, t_color col);

//get_next_line.c
char			*get_next_line(int fd);

//ft_atox.c
double			ft_atof(char **s, int *error);
unsigned char	ft_atoc(char **s, int *error);

//color.c
t_color			ft_new_color(int r, int g, int b);
t_color			ft_new_color_atoc(char **s, int *error);
t_color			ft_new_light_color_atoc(char **str, int *err);

t_color			ft_col_amplify(t_color col, double amplifier);
t_color			ft_col_add(t_color col, t_color col_add);
t_color			ft_colour_clamp(t_color col);
t_color			ft_colour_matrix_amplify(t_color col, t_color col_amplifier);
t_color			ft_colour_gamma_collect(t_color col, t_scene *scene);
t_color			ft_colour_gamma_apply(t_color col, t_scene *scene);

//cone.c
void			ft_intersect_cone(t_cone *cone, t_ray *ray, t_scene *scene);
t_cone			*ft_new_cone(t_vector3 position, t_vector3 orient, double rad);
void			ft_add_cone_props(t_cone *cone, char *s);
void			ft_add_cone(t_scene *scene, char *s);

//ft_render_next_frame.c
int				ft_render_next_frame(t_scene *scene);
void			ft_intersect_plane(t_plane *p, t_ray *r, t_bool bump,
					t_scene *scene);
void			ft_intersect_disc(t_disc *disc, t_ray *r, t_scene *scene);
double			ft_math_quadratic_equation(t_quad *q);
//ft_hud.c
void			ft_hud(t_scene *scene);

//vector3.c
t_vector3		ft_matrix3_subtract(t_vector3 a, t_vector3 b);
t_vector3		ft_matrix3_addition(t_vector3 a, t_vector3 b);
double			ft_vector3_distance(t_vector3 a, t_vector3 b);
t_vector3		ft_vector3_normalise(t_vector3 direc);
t_vector3		ft_vector3_multiply(t_vector3 direc, double multiply);
double			ft_vector3_sumpow2(t_vector3 a);
double			ft_vector3_scalar(t_vector3 a, t_vector3 b);
t_vector3		ft_vector3_qrotate(t_vector3 a, double theta, t_vector3 axis);
t_vector3		ft_vector3_rotate_yx(t_vector3 a, t_vector2 rot);
t_vector3		ft_vector3_rotate_xy(t_vector3 b, t_vector2 rot);
t_vector2		ft_vector3_arotate(t_vector3 a, t_vector3 b);
t_vector3		ft_new_vector3(double x, double y, double z);
t_vector2		ft_new_vector2(double u, double v);
t_vector3		ft_vector3_negate(t_vector3 a);
t_vector3		ft_vector3_cw(t_vector3 a);
t_vector3		ft_vector3_ccw(t_vector3 a);

//quaternion.c
double			ft_quaternion_sumpow2(t_quaternion q);
t_quaternion	ft_quaternion_normalise(t_quaternion q);
t_quaternion	ft_new_quaternion(double theta, t_vector3 axis);

void			ft_intersect(t_ray *r, t_scene *scene);
void			ft_raytrace(int x, int y, t_ray *r, t_scene *scene);
//ft_exit.c
void			ft_exit(int ex);
//ft_close_minirt.c
int				ft_close_minirt(void);
//ft_toggle.c
t_bool			ft_toggle(t_bool *n);
//ft_key_hook.c
int				ft_key_hook(int keyhook, t_scene *scene);
//ft_mouse_hook.c
int				ft_mouse_hook(int butt, int x, int y, t_scene *scene);
//ft_new_image.c
t_img			*ft_new_image(char *path, int w, int h, t_scene *scene);
//ft_key_hook.c
int				ft_move_light(int keyhook, t_scene *scene);
int				ft_toggle_flags(int keyhook, t_scene *scene);
int				ft_change_minquality(int keyhook, t_scene *scene);
int				ft_change_maxquality(int keyhook, t_scene *scene);
int				ft_move_camera(int keyhook, t_scene *scene);
int				ft_change_fov(int keyhook, t_scene *scene);
int				ft_rotate_camera(int keyhook, t_scene *scene);
void			ft_rotate_camera_xz(t_camera *camera, int theta);
void			ft_rotate_camera_y(t_camera *camera, int theta);
void			ft_redraw_frame(t_scene *scene);
void			ft_next_scene(t_scene *scene);
int				ft_close_minirt(void);
//views.c
void			ft_ray_orthographic(t_camera *cam, t_vector2 step, t_ray *r);
void			ft_ray_perspective_tan(t_camera *cam, t_vector2 step,
					t_ray *r);
void			ft_ray_perspective_spherise(t_camera *cam, t_vector2 step,
					t_ray *r);
void			ft_ray_perspective_spherise2(t_camera *cam, t_vector2 step,
					t_ray *r);
void			ft_ray_perspective_spherise3(t_camera *cam, t_vector2 step,
					t_ray *r);
void			ft_ray_perspective_quaternion(t_scene *scene, int x, int y,
					t_ray *r);
void			ft_ray_perspective_quaternion2(t_scene *scene, int x, int y,
					t_ray *r);

//ft_raytrace.c
void			ft_compute_light(t_ray *ray, t_scene *scene);
void			ft_update_window(t_scene *scene);
void			ft_reset_rays(t_scene *scene);
void			ft_animate(t_scene *scene);
void			ft_iterate_pixels_gamma_correction(t_scene *scene);

#endif