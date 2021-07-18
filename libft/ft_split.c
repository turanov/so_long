#include "libft.h"
static size_t	getsize(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (s[0] == c && s[0])
		s++;
	while (s[0])
	{
		while (s[0] && s[0] != c)
			s++;
		while (s[0] && s[0] == c)
			s++;
		cnt++;
	}
	return (cnt);
}

static char	**ft_free(char **ans, size_t idx)
{
	while (--idx >= 0)
		free(ans[idx]);
	free(ans);
	return (0);
}

static char	**rowmalloc(char **ans, char const *s, char c, size_t n)
{
	size_t	idx;
	size_t	cnt;

	idx = 0;
	while (idx < n)
	{
		while (s[0] == c)
			s++;
		cnt = 0;
		while (s[cnt] && s[cnt] != c)
			cnt++;
		ans[idx] = ft_calloc(cnt + 1, sizeof(char));
		if (!ans[idx])
			return (ft_free(ans, idx));
		ft_strlcpy(ans[idx], s, cnt + 1);
		s += cnt;
		idx++;
	}
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	size_t		n;
	char		**ans;

	if (!s)
		return (0);
	n = getsize(s, c);
	ans = ft_calloc(n + 1, sizeof(char *));
	if (!ans)
		return (0);
	rowmalloc(ans, s, c, n);
	return (ans);
}
