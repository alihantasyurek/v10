/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:20:31 by aatasyure         #+#    #+#             */
/*   Updated: 2024/03/17 04:14:24 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>

static void small_letter(char *string)
{
	int c;

	c = 0;
	while(string[c] != '\0')
	{
	if(string[c] >= 'A' && string[c] <= 'Z')
		string[c] += 32;
	c++;
	}
}

static int check_letter(char *string)
{
	int c;

	c = 0;
	while(string[c] != '\0')
	{
	if(string[c] >= 'A' && string[c] <= 'Z')
		return (1);
	c++;
	}
	return (0);
}

//#include <stdio.h>
void	execute_builtin_command(t_parse *parse, t_mini *m_mini)
{
	t_parse	*new_parse;

	new_parse = parse;
	if(check_letter(new_parse->cmd))
		small_letter(new_parse->cmd);

	if ((ft_strcmp(new_parse->cmd, "echo") == 0))
		exec_echo(new_parse, m_mini);
	if (ft_strcmp(new_parse->cmd, "cd" ) == 0)
		exec_cd(new_parse, m_mini);
	if ((ft_strcmp(new_parse->cmd, "pwd") == 0))
		exec_pwd(new_parse, m_mini);
	if ((ft_strcmp(new_parse->cmd, "env") == 0))
		exec_env(m_mini);
	if (ft_strcmp(new_parse->cmd, "export") == 0)
		exec_export(new_parse, m_mini);
	if (ft_strcmp(new_parse->cmd, "unset") == 0)
		exec_unset(new_parse, m_mini, 0, 0);
}

int	is_builtin(t_parse *data)
{
	if ((ft_strcmp(data->cmd, "echo") == 0) || (ft_strcmp(data->cmd,
				"ECHO") == 0))
		return (1);
	if ((ft_strcmp(data->cmd, "pwd") == 0) || (ft_strcmp(data->cmd,
				"PWD") == 0))
		return (1);
	if ((ft_strcmp(data->cmd, "env") == 0) || (ft_strcmp(data->cmd,
				"ENV") == 0))
		return (1);
	if ((ft_strcmp(data->cmd, "cd") == 0) || (ft_strcmp(data->cmd,
				"CD") == 0)) //changed
		return (1);
	if ((ft_strcmp(data->cmd, "export") == 0))
		return (1);
	if ((ft_strcmp(data->cmd, "unset") == 0))
		return (1);
	return (0);
}

int	ft_strchrindex_0(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	export_key_control(char *text)
{
	int	i;

	if (text[0] == '=' || ft_isdigit(text[0]))
		return (0);
	i = 0;
	while (text[i] && text[i] != '=' && (ft_isalnum(text[i]) || text[i] == '_'))
		i++;
	if (text[i] == '=' || !text[i])
		return (1);
	return (0);
}

void	edit_env(t_list *node, char *key, char *value, t_mini *m_mini)
{
	t_env	*env;

	while (node != NULL)
	{
		env = (t_env *)node->content;
		if (ft_strcmp(env->key, key) == 0)
		{
			if (env->value)
				free(env->value);
			env->value = ft_strdup(value);
			if (value)
				free(value);
			free(key);
			return ;
		}
		node = node->next;
	}
	edit_env_(node, key, value, m_mini);
}
