#include "libft.h"

size_t	ft_cstrlen(const char *str, char c)
{
    char	*copy_str;

    copy_str = (char *)str;
    while (*copy_str && *copy_str != c)
        copy_str++;
    return (copy_str - str);
}
