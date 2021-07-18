#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	p = malloc(i + 1);
	if (!p)
		return (0);
	p[i] = '\0';
	while (i--)
		p[i] = f(i, s[i]);
	return (p);
}
