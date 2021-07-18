#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ans;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ans = malloc(l1 + l2 + 1);
	if (!ans)
		return (0);
	ft_strlcpy(ans, s1, l1 + 1);
	ft_strlcpy(ans + l1, s2, l2 + 1);
	free(s1);
	free(s2);
	return (ans);
}
