/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:11:18 by fshields          #+#    #+#             */
/*   Updated: 2023/12/21 17:00:41 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*rtn;

	rtn = (t_list *) malloc(sizeof(t_list));
	if (rtn == NULL)
		return (NULL);
	rtn->content = content;
	rtn->next = NULL;
	return (rtn);
}

t_int_list	*ft_int_lstnew(int value)
{
	t_int_list	*rtn;

	rtn = (t_int_list *) malloc(sizeof(t_int_list));
	if (rtn == NULL)
		return (NULL);
	rtn->value = value;
	rtn->next = NULL;
	return (rtn);
}
