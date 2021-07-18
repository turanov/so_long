#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	if (c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static int	getint(const char *str, int i, int minus)
{
	int	ans;

	ans = 0;
	if (ft_isdigit(str[i]) == 1)
		ans = str[i++] - 48;
	while (ft_isdigit(str[i]) == 1)
	{
		ans *= 10;
		ans += str[i] - 48;
		i++;
	}
	if (minus == 1)
		ans *= -1;
	return (ans);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	i;

	i = 0;
	minus = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = 1;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	return (getint(str, i, minus));
}
