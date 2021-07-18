#include "libft.h"

int	ft_toupper(int str)
{
	if (str >= 97 && str <= 122)
		return (str - 32);
	return (str);
}
