#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		n;
	int		i;
	char	*ans;

	i = 0;
	n = ft_strlen(str);
	ans = (char *)malloc(n + 1);
	if (!ans)
		return (0);
	while (i < n)
	{
		ans[i] = str[i];
		i++;
	}	
	ans[i] = '\0';
	return (ans);
}
