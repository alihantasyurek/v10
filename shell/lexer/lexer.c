/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:23:46 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/15 20:27:59 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>

int	ignore_quote(char const *cmd, int i)
{
	if (cmd[i] == '\"')
	{
		i++;
		while (cmd[i] != '\"')
			i++;
	}
	else if (cmd[i] == '\'')
	{
		i++;
		while (cmd[i] != '\'')
			i++;
	}
	return (i);
}

static int	len_for_separate(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd || !*cmd)
		return (0);
	if (cmd[i] == '<' && cmd[i + 1] == '<')
		return (2);
	if (cmd[i] == '>' && cmd[i + 1] == '>')
		return (2);
	if (cmd[i] == '<' || cmd[i] == '>' || cmd[i] == '|')
		return (1);
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '>' && cmd[i] != '<'
		&& cmd[i] != '|')
	{
		if (cmd[i] == '\"' || cmd[i] == '\'')
		{
			i = ignore_quote(cmd, i) + 1;
		}
		else
			i++;
	}
	return (i);
}

static void separate_cmd(char *cmd, t_lexer **lex_list)
{
	int		len;
	char	*content;
	char	*trimmed_content;

	if (!cmd || !*cmd)
		return ;
	cmd = ft_strtrim(cmd, " ""\t"); //made it work with tab on the start and end as well
	len = len_for_separate(cmd);
	content = ft_substr(cmd, 0, len);
	trimmed_content = ft_strtrim(content, " ");
	free(content);
	ft_lstadd_back(&(*lex_list)->lex, ft_lstnew(trimmed_content));
	separate_cmd(cmd + len, lex_list);
	free(cmd);
}

void	lexer(t_mini *mini)
{
	mini->lex_list->lex = NULL; //abundant?
	separate_cmd(mini->cmd, &mini->lex_list);
}
