/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:30:14 by agesp             #+#    #+#             */
/*   Updated: 2019/04/05 13:30:22 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_intcpy(int *s1, int *s2, int size)
{
	int i;

	i = -1;
	while (++i <= size)
		s1[i] = s2[i];
	i++;
}
