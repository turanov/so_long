#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (size == 0)
		return (srclen);
	if (dstlen > size)
		return (srclen + size);
	ft_strlcpy(dst + dstlen, src, size - dstlen);
	return (dstlen + srclen);
}
