#include "libft.h"

static size_t	cmp(const char *big, const char *little, size_t i, size_t len)
{
	size_t	j;
	size_t	cnt;

	j = 0;
	cnt = 0;
	while (j < len && big[i + j] != '\0')
	{
		if ((char)big[i + j] == (char)little[j])
			cnt++;
		j++;
	}
	return (cnt);
}

char	*ft_strnstr (const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	if (n != 0)
	{
		while (i <= n - len && big[i] != '\0')
		{
			if (cmp(big, little, i, len) == len)
				return ((char *)(big + i));
			i++;
		}
	}
	return (0);
}
