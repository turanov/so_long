#include "libft.h"

int	ft_tolower(int str)
{
	if (str >= 65 && str <= 90)
		return (str + 32);
	return (str);
}
