/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:20:31 by aatasyure         #+#    #+#             */
/*   Updated: 2024/03/17 06:09:20 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>

static void make_lowercase(char *string)
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

static int check_case(char *string)
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

int		execute_builtin_command(t_parse *parse, t_mini *m_mini)
{
	char *temp;

	temp = NULL;
	temp = parse->cmd;

	if(check_case(parse->cmd))
		make_lowercase(parse->cmd);

	if ((ft_strcmp(parse->cmd, "echo") == 0))
		return(exec_echo(parse, m_mini),1);
	if (ft_strcmp(parse->cmd, "cd" ) == 0)
		return(exec_cd(parse, m_mini),1);
	if ((ft_strcmp(parse->cmd, "pwd") == 0))
		return(exec_pwd(parse, m_mini),1);
	if ((ft_strcmp(parse->cmd, "env") == 0))
		return(exec_env(m_mini),1);
	if (ft_strcmp(parse->cmd, "export") == 0)
		return(exec_export(parse, m_mini),1);
	if (ft_strcmp(parse->cmd, "unset") == 0)
		return(exec_unset(parse, m_mini, 0, 0),1);

	parse->cmd = temp;
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
