/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:02 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/26 02:26:44 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

/*
	Fill stack a
	Returns 0 if only 1 number is passed as argument
*/
int	fill_stack(int *num, t_stack *stack)
{
	int		i;
	t_list	*new;

	if (stack->size == 1)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		new = ft_lstnew(&num[i]);
		if (!new)
			return (0);
		ft_lstadd_back(&(stack->top), new);
		i++;
	}
	return (1);
}

/*
	return the min value in stack a
*/
int	get_min_value(t_stack *stack)
{
	t_list	*elem;
	int		min;

	elem = stack->top;
	min = *((int *)elem->content);
	while (elem->next != NULL)
	{
		if (min > *((int *)elem->next->content))
			min = *((int *)elem->next->content);
		elem = elem->next;
	}
	return (min);
}

int	get_max_value(t_stack *stack)
{
	t_list	*elem;
	int		max;

	elem = stack->top;
	max = *((int *)elem->content);
	while (elem->next != NULL)
	{
		if (max < *((int *)elem->next->content))
			max = *((int *)elem->next->content);
		elem = elem->next;
	}
	return (max);
}
