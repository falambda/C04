#include <unistd.h>

void	ft_putnbr(int nb)
{
	char number;
	long n;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		write (1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr (n / 10);
	number = '0' + n % 10;
	write (1, &number, 1);
}