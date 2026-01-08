/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 07:46:25 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 19:28:57 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
/*int	main(void)
{
	t_list *list = NULL;

	t_list *elem1 = ft_lstnew("!!!!!");
	t_list *elem2 = ft_lstnew("World");
	t_list *elem3 = ft_lstnew("Hello");

	ft_lstadd_back(&list, elem3); // Liste: "!!!!!"
	ft_lstadd_back(&list, elem2); // Liste: "World" -> "!!!!!"
	ft_lstadd_back(&list, elem1); // Liste: "Hello" -> "World" -> "!!!!!"

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
