#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	sign;

	sign = 1;
	ret = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		ret = ret * 10 + (str[i++] - 48);
	return (ret * sign);
}
