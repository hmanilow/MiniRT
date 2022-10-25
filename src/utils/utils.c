#include "../../inc/minirtMAIN.h"

size_t	ft_strlen(const char *str)
{
    unsigned int	i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return ((int)(i));
}

void	ft_putstr_fd(char *s, int fd)
{
    if (s == NULL)
        return ;
    write(fd, s, ft_strlen(s));
}

void	arg_error(char *sms)
{
    ft_putstr_fd("Error: ", 2);
    perror(sms);
    exit(1);
}
