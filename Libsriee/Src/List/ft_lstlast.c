/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 07:11:23 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 19:29:36 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*int	main()
{
	t_list *list = NULL;

	t_list *node1 = ft_lstnew("Premier");
	t_list *node2 = ft_lstnew("Deuxième");
	t_list *node3 = ft_lstnew("Troisième");

	ft_lstadd_front(&list, node3); // list = "Troisième"
	ft_lstadd_front(&list, node2); // list = "Deuxième" -> "Troisième"
	ft_lstadd_front(&list, node1); // list = 1er -> 2e -> 3e

	t_list *last = ft_lstlast(list);

	// Affichage du dernier élément
	if (last && last->content)
		printf("Dernier élément de la liste : %s\n", (char *)last->content);
	else
		printf("La liste est vide ou mal initialisée.\n");

	return 0;
}*/
