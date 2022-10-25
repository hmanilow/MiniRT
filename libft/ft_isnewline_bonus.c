#include "libft.h"

int	is_newline(char *str)
{
    while (*str)
    {
        if (*str == '\n')
            return (1);
        str++;
    }
    return (0);
}
