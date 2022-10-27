#include "../../inc/minirtMAIN.h"

int	str_to_int(char **s)
{
    int	i;
    int	sign;

    i = 0;
    sign = 1;
    if (**s == '-' && *((*s)++))
        sign = -1;
    while (ft_isdigit(**s))
        i = i * 10 + (*((*s)++) - '0');
    skip_space(s);
    return (i * sign);
}

void	skip_space(char **s)
{
    while (**s == 32 || **s == 9)
        (*s)++;
}

//for parsing
