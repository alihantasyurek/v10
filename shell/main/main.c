/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:23:53 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/17 04:40:24 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>

int		g_heredoc_sig;

void	get_readline(t_mini *mini)
{
	mini->cmd = readline("🟢 emmodogl&&aatasyure$ ");
	if (mini->cmd && !is_space(mini->cmd))
	{
		free(mini->cmd);
		get_readline(mini);
	}
	if (!mini->cmd)
	{
		free_loop(0, mini);
		free_(mini);
		free(mini->lex_list);
		free(mini);
		exit(1);
	}
	add_history(mini->cmd);
}


void	parser(t_mini *mini, char **env, int control)
{
	control = check(mini);
	if (!control)
	{
		//error_free(&(mini->lex_list)->lex);
		proper_free(&mini->lex_list->lex);//added new free func
		free_loop(control, mini);//maybe only free cmd instead?
		return ;
	}
	if (ft_strcmp(mini->cmd, ""))
	{
		if (our_parser(mini))
			exec(env, mini);
	}
	free_loop(control, mini);
}

//yorum
void	start_minishell(t_mini *mini, char **env, int control)
{
	while (42)
	{
		get_readline(mini);
		if (quote_check(mini->cmd, '\'', '\"'))
		{
			lexer(mini);
			expander(mini);
			parser(mini, env, control);
		}
		else
		{
			(free(mini->cmd));
			continue ;
		}
	}
}

static int argument_control(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (printf(W_ARGS), 1);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini;

	if (argument_control(argc, argv) != 0) 
		return (127);
	if (init(&mini) != 0)
		return (printf(A_ERR), 1); 
	if (env_get(env, &mini))
		return (free_init_check(mini), 1);
	signals_control();
	start_minishell(mini, env, 0);
}
