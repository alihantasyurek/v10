/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:23:25 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/15 21:09:58 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	free_init_check(t_mini *mini)
{
	if (mini->env)
		free_(mini);
	if (mini)
		free(mini);
	return ((void)printf(ENV_ERR));
}

void	proper_free(t_list **node)
{
	t_list *curr_node;
	t_list *temp;

	curr_node = *node;

	while(curr_node != NULL)
	{
		free(curr_node->content);
		curr_node->content = NULL;
		temp = curr_node;
		curr_node = curr_node->next;
		free(temp);
		temp = NULL;
	}
}