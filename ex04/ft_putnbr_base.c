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

void	print_reverse(char *str, char *buffer)
{
	while (str > buffer)
	{
		str--;
		write(1, str, 1);
	}
}

void	print_number(long n, char *base, int i_base)
{
	char	buffer[33];
	char	*str;

	str = buffer;
	if (n == 0)
	{
		write(1, base, 1);
		return;
	}
	while (n > 0)
	{
		*str++ = base[n % i_base];
		n /= i_base;
	}
	print_reverse(str, buffer);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i_base;
	long	n;

	i_base = parse_base(base);
	if (!i_base)
		return;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	print_number(n, base, i_base);
}