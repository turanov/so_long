#include "libft.h"

void	*ft_memccpy (void *destination, const void *source, int c, size_t n)
{
	if ((unsigned char *)destination == 0 && (unsigned char *)source == 0)
		return (0);
	while (n > 0)
	{
		 *((unsigned char *)destination) = *((unsigned char *)source);
		 if ((unsigned char)c == *((unsigned char *)source))
			return (destination + 1);
		 destination++;
		 source++;
		 n--;
	}
	return (0);
}
