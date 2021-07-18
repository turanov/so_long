#include "libft.h"

static int	getsize(int n)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*fun(char *ans, int n, int size)
{
	long	m;

	m = n;
	if (m < 0)
	{
		m *= -1;
		ans[0] = '-';
	}
	if (m == 0)
		ans[0] = '0';
	while (m)
	{
		ans[size - 1] = m % 10 + 48;
		m /= 10;
		size--;
	}
	return (ans);
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		size;

	size = getsize(n);
	if (n < 0)
		size++;
	ans = malloc(size + 1);
	if (!ans)
		return (0);
	ans[size] = '\0';
	return (fun(ans, n, size));
}
