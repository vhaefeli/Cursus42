/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/02 15:21:01 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	solution pour pouvoir free la de figure sans ""
*/
static char	**copy_argv(int argc, char **argv)
{
	char	**cpy;
	int		i;

	cpy = malloc(sizeof(char *) * argc);
	i = 0;
	while (argv[i])
	{
		cpy[i] = ft_strdup(argv[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

/*
	return a pointer of char *arrays with user data
*/
static char	**get_user_data(int argc, char **argv)
{
	char	**values;

	if (!argv)
		return (NULL);
	values = ++argv;
	if (argc == 2)
		values = ft_split(argv[0], ' ');
	else
		values = copy_argv(argc, argv);
	return (values);
}

/*
	Writes Error if a char is not a digit
	Does nothing if user writes + or - before the number
	Returns an array of integers
*/
static void	is_number(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '+' || array[i][j] == '-')
				j++;
			if (!ft_isdigit(array[i][j]))
				print_error_and_exit();
			j++;
		}
		i++;
	}
}

/*
	Writes Error at first found duplicated string / number
*/
static void	find_duplicate(char **array)
{
	int		i;
	int		j;
	char	*value_to_check;

	i = 0;
	while (array[i])
	{
		value_to_check = array[i];
		i++;
		j = i;
		while (array[j])
		{
			if (!ft_strcmp(array[j], value_to_check))
				print_error_and_exit();
			j++;
		}
	}
}

/*
	/!\ à la copie d'adresse
	n : pointeur sur int permettant de réserver une nouvelle adresse mémoire
	Contient les mêmes valeurs que le user a entré, pour remplir la liste
	Evite de trier ma pile lorsque je trie mon tableau template
	template->int_array : me permet de choisir mes pivots
*/
static int	fill_stack(char **str, t_template *template, t_stack *a)
{
	char	*str_cpy;
	int		i;
	int		*n = NULL;

	i = 0;
	str_cpy = NULL;
	while (str[i]) // des free a faire ici
	{
		str_cpy = str[i];
		template->int_array[i] = ft_atoi_check_overflow(str_cpy);
		n = malloc(sizeof(int *));
		*n = template->int_array[i];
		ft_lstadd_back(&a->top, ft_lstnew(n));
		printf("liste neuve: [%d]\n", get_content(*a->top));
		printf("liste neuve: [%d]\n", get_content(*a->top->next));
		if (template->int_array != NULL) // si on a reussi a remplir la chaine
		{
			ft_free_ppointer(str);
			free(str_cpy);
		}
		++i;

	}
	return (1);
}

/*
	Je malloc les deux cas de figure : avec et sans ""
	Récupère le nombre de valeurs à trier
	Je copie chaque string sur une nouvelle adresse (l125)
	Les convertis les string en integer
	Initialise ma chaine, ajoute à chaque élément le contenu.
*/
void	get_data(int argc, char **argv , t_stack *a, t_template *template)
{
	char	**str;

	str = get_user_data(argc, argv);
	a->size = ft_count_arrays(str);
	if (a->size == 1)
		free_ppointer_and_exit(str);
	is_number(str);
	find_duplicate(str);
	template->int_array = (int *)malloc(sizeof(int) * a->size);
	if (!template->int_array)
		free(template->int_array);
	if (!fill_stack(str, template, a))
	{
		free(template->int_array);
		ft_lstclear(&(a->top), free);
		free(str);
	}
}
