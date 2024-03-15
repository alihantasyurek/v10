/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:09:06 by aatasyure         #+#    #+#             */
/*   Updated: 2024/03/15 20:58:23 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*spc;

	i = ft_strlen(s1);
	if(i == 0)
		return NULL;
	i += 1;
	spc = (char *)malloc(i * sizeof(char));
	if (!spc)
		return (NULL);
	ft_strlcpy(spc, s1, i);
	return (spc);
}
