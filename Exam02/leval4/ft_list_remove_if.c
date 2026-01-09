/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 07:03:13 by malhendi          #+#    #+#             */
/*   Updated: 2025/12/11 07:03:13 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
}

/*
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current;
    t_list *previous;
    t_list *to_delete;

    while (begin_list && *begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        to_delete = *begin_list;
        *begin_list = (*begin_list)->next;
        free(to_delete);
    }
    current = *begin_list;
    previous = NULL;
    while (current)
    {
        if (cmp(current->data, data_ref) == 0)
        {
            to_delete = current;
            if (previous)
                previous->next = current->next;
            current = current->next;
            free(to_delete);
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}
*/