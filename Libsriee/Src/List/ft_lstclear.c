/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:26:56 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 19:29:12 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
/*
static void	del(void *content)
{
	free(content);
}*/
/*
int main(void)
{
    t_list *list = ft_lstnew(ft_strdup("Premier"));
    list->next = ft_lstnew(ft_strdup("Deuxième"));
    list->next->next = ft_lstnew(ft_strdup("Troisième"));

    while (list)
    {
        printf("Contenu : %s\n", (char *)list->content);
        list = list->next;
    }
    ft_lstclear(&list, ft_del);

    if (list == NULL)
        printf("Liste bien nettoyée !\n");
    return 0;
}*/
