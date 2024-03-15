/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:21:16 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/15 20:24:15 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	edit_env_(t_list *node, char *key, char *value, t_mini *m_mini)
{
	t_env	*new_env;

	if (node == NULL)
	{
		new_env = malloc(sizeof(t_env));
		if (!new_env)
			return ;
		new_env->key = key;
		new_env->value = value;
		ft_lstadd_back(&(m_mini->env), ft_lstnew(new_env));
	}
}

void	exec_pwd(t_parse *data, t_mini *m_mini)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		write(data->outfile, cwd, ft_strlen(cwd));
		write(1, "\n", 1);
		m_mini->exec_status = 0;
	}
	else
	{
		perror("getcwd");
		m_mini->exec_status = 1;
	}
	free(cwd);
}


char	*get_home(t_mini *m_mini)
{
	t_list	*tmp;
	t_env	*env;

	tmp = m_mini->env;
	while (tmp)
	{
		env = tmp->content;
		if (!ft_strcmp(env->key, "HOME"))
			return (env->value);
		tmp = tmp->next;
	}
	return (NULL);
}
