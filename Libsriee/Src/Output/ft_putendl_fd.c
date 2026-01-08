/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:25:55 by sariee            #+#    #+#             */
/*   Updated: 2025/04/09 09:40:55 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	else
	{
		write (fd, s, ft_strlen(s));
		ft_putchar_fd('\n', fd);
	}
}
/*int	main()
{
	ft_putendl_fd("Salut", 1);
}*/