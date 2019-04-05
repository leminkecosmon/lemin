/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:07:04 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:07:06 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		hexa(char *str, int *x)
{
	if (str[(*x)] != '0' && str[(*x + 1)] != 'x')
		return (1);
	(*x) += 2;
	while (str[(*x)])
		if (ft_ishexa((str[(*x)])))
			(*x)++;
		else
			return (1);
	return (0);
}