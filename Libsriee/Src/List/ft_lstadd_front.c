/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:27:46 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 19:29:04 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*int	main(void)
{
	t_list *list = NULL;

	t_list *elem1 = ft_lstnew("!!!!!");
	t_list *elem2 = ft_lstnew("World");
	t_list *elem3 = ft_lstnew("Hello");

	ft_lstadd_front(&list, elem1); // Liste: "!!!!!"
	ft_lstadd_front(&list, elem2); // Liste: "World" -> "!!!!!"
	ft_lstadd_front(&list, elem3); // Liste: "Hello" -> "World" -> "!!!!!"

	t_list *current = list;
	printf("Contenu de la liste:\n");
	while (current)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");

	return 0;
}*/
