/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:16:54 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 19:29:42 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!f || !*f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
static void	ft_del(void *content)
{
	
	free(content);
}
static void	print_str(void *content)
{
	printf("%s\n", (char *)content);
}
static void	*to_upper_str(void *content)
{
	char	*str;
	int		i;
	char	*copy;

	str = (char *)content;
	copy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = ft_toupper(str[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
int main(void)
{
	t_list	*original = ft_lstnew(ft_strdup("salut"));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("toi")));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("bien")));

	// Map vers une nouvelle liste avec mots en majuscules
	t_list *mapped = ft_lstmap(original, to_upper_str, ft_del);

	// Affiche les 2 listes
	printf("Original:\n");
	ft_lstiter(original, print_str);
	printf("\nMapped:\n");
	ft_lstiter(mapped, print_str);

	// Nettoyage mémoire
	ft_lstclear(&original, ft_del);
	ft_lstclear(&mapped, ft_del);
	return 0;
}*/
