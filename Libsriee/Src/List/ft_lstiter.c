/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:32:38 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 19:29:26 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*static void	to_upper_str(void *content)
{
    char	*str;
	int		i;

	str = (char *)content;
	i = 0;
    while (str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
}
static void	print_str(void *content)
{
		printf("%s\n", (char *)content);
}
int main()
{
	t_list *elem1 = ft_lstnew(ft_strdup("Bonjour"));
	elem1->next = ft_lstnew(ft_strdup("les"));
	elem1->next->next = ft_lstnew(ft_strdup("amis!"));

	ft_lstiter(elem1, print_str);
	ft_lstiter(elem1, to_upper_str);
	ft_lstiter(elem1, print_str);
	return (0);
}*/
