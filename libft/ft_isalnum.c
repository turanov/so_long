#include "libft.h"

int	ft_isalnum(int ch)
{
	if (ft_isalpha(ch) == 1 || ft_isdigit(ch) == 1)
		return (1);
	return (0);
}
