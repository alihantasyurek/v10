/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:22:07 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/15 20:29:24 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	env_get(char **env, t_mini **mini)
{
	t_env	*key_v;
	char	**str;

	while (*env)
	{
		key_v = malloc(sizeof(t_env));
		if (!key_v)
			return (printf(A_ERR), 1);
		str = ft_split(*env, '=');
		if(str[0] == NULL) // choose one of the above
			key_v->key = NULL;
		else
			key_v->key = ft_strdup(str[0]);
		if(str[1] == NULL)
			key_v->value = NULL;
		else
			key_v->value = ft_strdup(str[1]);

		ft_lstadd_back(&(*mini)->env, ft_lstnew(key_v));
		free_str(str);
		env++;
	}
	return (0);
}
