#include "libft.h"

int	ft_isascii(int ch)
{
	if (ch >= 0x00 && ch <= 0x7F)
		return (1);
	return (0);
}
