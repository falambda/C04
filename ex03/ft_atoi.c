int	ft_char_is_numeric(char c)
{
		if (!((c >= '0') && (c <= '9')))
		{
			return (0);
		}
	return (1);
}

int	ft_char_is_sign(char c)
{
		if (!((c == '-') || (c == '+')))
		{
			return (0);
		}
	return (1);
}

int	ft_process_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int char_to_int (char c)
{
	return (c - '0');
}
	
int ft_atoi(char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while (*str == ' ')// || (*str >= 9 && *str <= 13))
		str++;
	while (ft_char_is_sign(*str))
	{
		sign *= ft_process_sign(*str);
		str++;
	}
	while (ft_char_is_numeric(*str))
	{
		result = result * 10 + char_to_int(*str);
		str++;
	}
	return (result * sign);
}