/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:15:13 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 19:29:19 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
static void	ft_del(void *content)
{
	free(content);
	printf("Suppression du contenu: %s\n", (char *)content);
}
int	main()
{
	t_list *elem1 = ft_lstnew(ft_strdup("Bonjour"));

	if (!elem1)
		return (1);
	printf("Avant suppression: %s\n", (char *)elem1->content);
	ft_lstdelone(elem1, ft_del);
	return (0);
}*/
