#include "../inc/minirtMAIN.h"

int	main(int argc, char **argv)
{
    t_base	*base;

    base = NULL;
    base = init();
    if (!parse(argc, argv, base) || !base)
        return (1);
    controller(base);
    return (0);
}

//todo handling
