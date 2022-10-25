#include "libft.h"

int	ft_pow_recursive(int basis, int exponent)
{
    if (basis == 0)
        return (1);
    else if (exponent == 1)
        return (basis);
    else if (exponent % 2 == 0)
        return (ft_pow_recursive(basis * basis, exponent / 2));
    else
        return (ft_pow_recursive(basis * basis, exponent / 2) * basis);
}
