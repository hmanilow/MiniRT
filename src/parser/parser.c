#include "../../inc/minirtMAIN.h"

static void	parse_line(t_base *base, t_figures **figs, char **strptr)
{
    char	*str;

    str = *strptr;
    if (*str == 'R' && *(str++))
        parse_resol(base, &str);
    else if (*str == 'A' && *(str++))
        parse_amb_light(base, &str);
    else if (*str == 'C' && *(str++))
        parse_cam(base, &str);
    else if (*str == 'L' && *(str++))
        parse_light(base, &str);
    else if (*str == 'c' && *(str + 1) == 'y' && *(str++) && *(str)++)
        parse_cylinder(figs, &str, base->scene);
    else if (*str == 's' && *(str + 1) == 'p' && *(str++) && *(str)++)
        parse_sphere(figs, &str, base->scene);
    else if (*str == 'p' && *(str + 1) == 'l' && *(str++) && *(str)++)
        parse_plane(figs, &str, base->scene);
    *strptr = str;
}

static void	parse_element(t_base *base, t_figures **figs, char *line)
{
    if (*line)
        parse_line(base, figs, &line);
}

static void	read_file(t_base *base, t_figures **figs, int fd)
{
    char		*line;
    int			read_status;

    *figs = base->scene->figs;
    read_status = -1;
    read_status = get_next_line(fd, &line);
    if (read_status == -1)
        arg_error("Can't open");
    while (read_status > 0)
    {
        parse_element(base, figs, line);
        free(line);
        line = NULL;
        read_status = get_next_line(fd, &line); //reading
    }
    if (line)
    {
        parse_element(base, figs, line);
        free(line);
        line = NULL;
    }
    base->scene->figs = *figs;
}

int	parse(int argc, char **argv, t_base *base)
{
    int			fd;
    int			read_status;
    t_figures	*figs;

    figs = base->scene->figs;
    read_status = -1;
    if (argc != 2)
        arg_error("Usage ./miniRt *filename*.rt"); //handling
    fd = open(argv[1], O_RDONLY);
    if (fd <= 0)
        arg_error("Can't open file");
    read_file(base, &figs, fd);
    close(fd);
    return (1);
}
