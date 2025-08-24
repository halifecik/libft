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
	char	*ret;

	size = ft_digits(n);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	sign = 1;
	ret[size] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		sign = -1;
	}
	while (size-- > (sign == -1))
	{
		ret[size] = 48 + (sign * (n % 10));
		n /= 10;
	}
	return (ret);
}
