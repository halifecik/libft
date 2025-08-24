#include "libft.h"

static int	ft_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*rtn;

	size = ft_digits(n);
	rtn = malloc(sizeof(char) * (size + 1));
	if (!rtn)
		return (NULL);
	sign = 1;
	rtn[size] = '\0';
	if (n < 0)
	{
		rtn[0] = '-';
		sign = -1;
	}
	while (size-- > (sign == -1))
	{
		rtn[size] = '0' + (sign * (n % 10));
		n /= 10;
	}
	return (rtn);
}
