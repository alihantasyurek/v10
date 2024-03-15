/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:23:25 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/15 20:27:16 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	free_init_check(t_mini *mini)
{
	if (mini->env)
		free_(mini);
	//if (mini->lex_list->lex) // find where lex_lists are used
		//free(mini->lex_list->lex);
	//if (mini->lex_list)
		//free(mini->lex_list);
	if (mini)
		free(mini);
	return ((void)printf(ENV_ERR));
}
