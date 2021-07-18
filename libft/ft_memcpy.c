#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	void	*p;

	p = destination;
	if ((char *)destination == 0 && (char *)source == 0)
		return (0);
	while (n > 0)
	{
		 *((char *)destination) = *((char *)source);
		 destination++;
		 source++;
		 n--;
	}
	return (p);
}
