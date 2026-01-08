/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:52:36 by samuelriee        #+#    #+#             */
/*   Updated: 2025/04/25 16:14:14 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

static int	check_longmax(char c, long result, int sign)
{
	if (result > LONG_MAX / 10 + (c - 48))
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long long	i;
	int			sign;
	long long	result;
	int			check;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		check = check_longmax(i, result, sign);
		if (check != 1)
			return (check);
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (sign * result);
}
/* int	main()
{
	char str[] = "-99999999999999999999999999";

	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
}*/