#include "../minirtMAIN.h"

t_img * ft_init_img(t_mlx *mlx)
{
    t_img   *img;
    int     h;
    int     w;

    if (!(img = malloc(sizeof(*img))))
        print_error("MAlloc error", MALLOC_ERROR); //malloc error macros
    w = 1080;
    h = 720;
    if (!(img->img_ptr = mlx_new_image(mlx->mlx_ptr, resolution->w, resolution->h)))
        print_error("Minilibx error", MLX_ERROR);
    if (!(img->data = (unsigned char*)mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel), &(img->size_line), &(img->endian))))
        print_err_and_exit("Minilibx error", MLX_ERROR);
    return (img);
}

int main(const int argc, char **argv)
{
    t_scene *scene;
    t_img   *img;
    t_mlx   *mlx;

    scene = fd_openning(argc, argv);
    mlx = ft_malloc_mlx_init();
    img = ft_init_img(mlx)
    return (0);
}
