#include "libft.h"

void	*ft_memset (void *destination, int c, size_t n)
{
	void	*p;

	p = destination;
	while (n--)
	{
		*((char *)destination++) = c;
	}
	return (p);
}
