/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:21:07 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/15 20:24:35 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	change_old(char *str, t_mini *m_mini)
{
	t_list	*node;
	t_env	*env;
	char	*targetkey;
	int		flag;

	flag = 0;
	targetkey = "OLDPWD";
	node = m_mini->env;
	while (node)
	{
		env = (t_env *)node->content;
		if (!ft_strcmp(env->key, targetkey))
		{
			free(env->value);
			env->value = ft_strdup(str);
			return ;
		}
		node = node->next;
		if (!node)
			flag = 1;
	}
	if (flag == 1)
		create_oldpwd(m_mini, str);
}

void	create_oldpwd(t_mini *m_mini, char *str)
{
	t_env	*newenv;

	newenv = malloc(sizeof(t_env));
	if (!newenv)
		return ;
	newenv->key = ft_strdup("OLDPWD"); //ft_
	newenv->value = ft_strdup(str); //ft_
	ft_lstadd_back(&(m_mini->env), ft_lstnew(newenv));
	return ;
}

void	change_pwd(t_parse *data, t_mini *m_mini)
{
	char	*targetkey;
	t_list	*node;
	t_env	*env;

	targetkey = "PWD";
	node = m_mini->env;
	while (node)
	{
		env = (t_env *)node->content;
		if (!ft_strcmp(env->key, targetkey))
		{
			if (env->value)
				free(env->value);
			if (data->text && !ft_strcmp(data->text[0], "~"))
				env->value = get_home(m_mini);
			else
				env->value = getcwd(NULL, 0);
			return ;
		}
		node = node->next;
	}
}
