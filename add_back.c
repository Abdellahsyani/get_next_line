/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:38:07 by asyani            #+#    #+#             */
/*   Updated: 2024/11/23 17:40:43 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_back(t_list **lst, t_list *data)
{
	t_list	*head;

	head = *lst;
	if (!lst || !data)
		return ;
	if (!head)
	{
		*lst = data;
		return ;
	}
	while (head->next)
	{
		head = head->next;
	}
	head->next = data;
}
