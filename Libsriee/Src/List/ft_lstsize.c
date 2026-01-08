/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:04:16 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 19:29:57 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*int	main()
{
	t_list	*liste = NULL;

	t_list 	*elem1 = ft_lstnew("un");
	t_list 	*elem2 = ft_lstnew("Deux");
	t_list 	*elem3 = ft_lstnew("Trois");

	ft_lstadd_front(&liste, elem3);
	ft_lstadd_front(&liste, elem2);
	ft_lstadd_front(&liste, elem1);

	int 	taille = ft_lstsize(liste);
	printf("%d\n", taille);
	
	return (0);
}*/
