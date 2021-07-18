#include "libft.h"

char	*ft_strrchr (const char *str, int ch)
{
	char	*p;
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(str);
	p = (char *)str;
	while (i <= n)
	{
		if (p[n - i] == ch)
			return (p + (n - i));
		i++;
	}
	return (0);
}
