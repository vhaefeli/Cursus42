/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/27 02:16:17 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	retourne la valeur de l'élément souhaité, à l'emplacement choisi
	utile pour trouver le milieu de la liste
	utile pour trouver le pivot de comparaison
*/
/* static t_list	*get_element(t_stack *a, int counter)
{
	t_list	*elem;

	elem = a->top;
	while (counter--)
	{
		if (elem == NULL)
			return NULL;
		elem = elem->next;
	}
	return (elem);
} */

/*
	Retourne une valeur pas liée au contenu de la pile a
	Définie selon les valeurs min et max de la pile ainsi que du nb à trier
	Utilisé comme comparaison pour le big sort (si plus petit, pb(a, b))
*/
/* static int	get_pivot_location(t_stack *a)
{
	if (a->size <= 100)
		return (5);
	if (a->size > 100)
		return (11);
	return (-1);
} */

/*
	passer les valeurs plus petites que le pivot dans la pile b
	passer les valeurs max de b sur la pile a, ce qui va trier
*/
void	big_sort(t_stack *a, t_stack *b)
{
	int		average;
	t_list	*min;
	t_list	*max;
	int		size;

	while (a->size)
	{
		size = a->size;
		min = get_min_value(a);
		max = get_max_value(a);
		if (min == NULL || max == NULL)
			break ;
		average = (get_content(*min) + get_content(*max)) / 4;
		printf("average : %i\n", average);
		while (a->top && size) //size permet de définir quand s'arrêter
		{
			if (get_content(*a->top) <= average)
				pb(a, b); // push sur pile b
			else
				ra(a); // rotate pile a, premier element devient le dernier
			--size;
		}
	}
	if (TEST)
	{
		printf("size of a : %i\n", a->size);
		printf("size of b : %i\n", b->size);
		//printf("b last : %d\n", get_content(*(ft_lstlast(b->top))));
		//printf("b fist : %d\n", get_content(*b->top));
		print_stack(a, b);
	}
	while (b->size)
	{
		max = get_max_value(b);
		if (max == NULL)
			break ;
		if (get_content(*b->top) == get_content(*max))
			pa(b, a); // push sur pile a
		else
			rb(b);
	}
}
