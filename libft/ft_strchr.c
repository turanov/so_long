#include "libft.h"

char	*ft_strchr (const char *str, int ch)
{
	char	*p;

	p = (char *)str;
	while (*p != '\0')
	{
		if (*p == ch)
			return (p);
		p++;
	}
	if (*p == ch)
		return (p);
	return (0);
}
