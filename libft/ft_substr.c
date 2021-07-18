#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*ans;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size < len)
		len = size;
	ans = malloc(len + 1);
	if (!ans)
		return (0);
	if (start >= size)
		len = 0;
	ft_strlcpy(ans, s + start, len + 1);
	return (ans);
}
