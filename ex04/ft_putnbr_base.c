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

void	ft_putnbr_base(int nbr, char *base)
{
	int		i_base;
	char	*str;
	char	buffer[33];
	long	n;

	str = buffer;
	n = nbr;
	i_base = parse_base(base);
	if (i_base == 0)
		return;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
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