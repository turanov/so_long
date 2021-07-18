#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;
	size_t			i;

	i = 0;
	a1 = (unsigned char *)str1;
	a2 = (unsigned char *)str2;
	while (i < n && a1[i] != '\0' && a2[i] != '\0')
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (a1[i] - a2[i]);
}
