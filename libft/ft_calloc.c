#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*p;

	p = malloc(nitems * size);
	if (!p)
		return (0);
	ft_bzero(p, nitems * size);
	return ((void *)p);
}
