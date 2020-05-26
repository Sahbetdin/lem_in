/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 04:14:18 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 16:58:06 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** copy src_path to dest_path max n elements.
** if encounter -1 then stop
** the result is that all src_path should be in dest_path.
** even -1 elements
*/

void	copy_paths(int *dest_path, int *src_path, int n)
{
	int i;

	i = 0;
	while (i < n && (src_path[i] != -1 || dest_path[i] != -1))
	{
		dest_path[i] = src_path[i];
		i++;
	}
}

/*
** used for reversing paths since, the elements start from end_vertex.
** the path consists of nodes and then -1's
** reverses arr without taking into account -1's;
** b is temporary value
*/

void	reverse_array(int *arr, int n)
{
	int i;
	int i_2;
	int j;
	int b;

	i = -1;
	while (i < n && arr[++i] != -1)
		;
	i_2 = i / 2;
	j = 0;
	while (j < i_2)
	{
		b = arr[j];
		arr[j] = arr[i - 1 - j];
		arr[i - 1 - j] = b;
		j++;
	}
}
