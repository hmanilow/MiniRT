#include "../../minirtMAIN.h"

t_scene *parse(int fd)
{
    t_scene *scene;


    return (scene);
}

t_scene *fd_openning(const int argc, char **argv)
{
    t_scene *scene;
    int     fd;

    //handle individual cases
    if (argc < 2)
        print_error("Expecting file with a .rt extension", 1);
    if (argc > 2)
        print_error("Too many arg", 1);
    if (argc == 2 && ft_strncmp_reverse(argv[1], ".rt", 3))
        print_error("First arg must be with a .rt extension", 1);
    if ((fd = open(argv[1], O_RDONLY)) == -1) // only read
        print_error(strerror(errno), errno);
    if (!(scene = parse(fd)))
        print_error("Parse error", 1);
    if (close(fd) == -1)
        print_error(strerror(errno), errno);
    return (scene);
}
