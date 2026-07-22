#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		{
			return (*s1 - *s2);
		}
	}
	return (*s1 - *s2);
}

char int_to_char_extended (int i)
{	
	if (i >= 0 && i <= 9)
		return (i + '0');
	if (i == 10)
		return ('A');
	if (i == 11)
		return ('B');
	if (i == 12)
		return ('C');
	if (i == 13)
		return ('D');
	if (i == 14)
		return ('E');
	if (i == 15)
		return ('F');
	else
		return('\0');
}

int parse_base(char *base)
{
	int i_base;

	if (!(ft_strcmp(base, "0123456789")))
		i_base = 10;
	else if (!(ft_strcmp(base, "01")))
		i_base = 2;
	else if (!(ft_strcmp(base, "0123456789ABCDEF")))
		i_base = 16;
	else if (!(ft_strcmp(base, "01234567")))
		i_base = 8;
	else 
		return (0);
	return (i_base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i_base;
	int i;
	char *str;

	i = 0;
	i_base = parse_base(base);
	while (nbr % i_base != i_base)
	{
		*str++ = int_to_char_extended(nbr % i_base);
		nbr /= i_base;
		i++;
	}
	while ((i > 0))
	{
		write (1, (str - 1), 1);
		str--;
		i--;
	}
}
