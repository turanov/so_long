#include "libft.h"

static void	solve(int n, int fd)
{
	int	k;

	k = 1;
	if (n < 0)
		k = -1;
	if (n <= 9 && n >= -9)
	{
		ft_putchar_fd(n * k + 48, fd);
		return ;
	}
	solve(n / 10, fd);
	ft_putchar_fd((n % 10) * k + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		solve(n, fd);
}
