#include "libft.h"

void	*ft_memchr (const void *arr, int c, size_t n)
{
	char	*p;

	p = (char *)arr;
	while (n--)
	{
		if (*p == c)
		{
			return ((void *)p);
		}
		p++;
	}
	return (0);
}
