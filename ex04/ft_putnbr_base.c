#include <unistd.h>

int	parse_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		b;

	b = parse_base(base);
	if (!b)
		return;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= b)
		ft_putnbr_base(n / b, base);
	write(1, &base[n % b], 1);
}