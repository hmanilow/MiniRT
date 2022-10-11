#include "../../minirtMAIN.h"

static size_t	ft_strlen(const char *str)
{
    unsigned int	i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return ((int)(i));
}

static void	ft_putstr_fd(char *s, int fd)
{
    if (s == NULL)
        return ;
    write(fd, s, ft_strlen(s));
}

int ft_strncmp_reverse(char *argv, char *str, int a)
{

}

void print_error(const char *str, const int error)
{
    ft_putstr_fd("Error: ", STDERR_FILENO);
    ft_putstr_fd(str, STDERR_FILENO);
    ft_putstr_fd("\n", STDERR_FILENO);
    exit(error);
}
