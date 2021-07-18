#include "libft.h"

void	*ft_memmove (void *destination, const void *source, size_t n)
{
	char		*p1;
	char		*p2;
	size_t		i;

	i = 0;
	p1 = destination;
	p2 = (char *)source;
	if (p1 == 0 && p2 == 0)
		return (0);
	if (p1 > p2)
		while (n--)
			p1[n] = p2[n];
	else if (p1 < p2)
	{
		ft_memcpy(destination, source, n);
	}
	return (destination);
}
