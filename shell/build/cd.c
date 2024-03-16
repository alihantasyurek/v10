/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:48:33 by emmodogl          #+#    #+#             */
/*   Updated: 2024/03/17 00:55:31 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>

void	exec_cd1(char *str, t_parse *data, t_mini *m_mini)
{
	change_old(str, m_mini);
	chdir(get_home(m_mini));
	change_pwd(data, m_mini);
	m_mini->exec_status = 0;
}

void	exec_cd(t_parse *data, t_mini *m_mini)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (data->text && data->text[0])
	{
		if (chdir(data->text[0]) == 0)
		{
			change_old(str, m_mini);
			change_pwd(data, m_mini);
			m_mini->exec_status = 0;
		}
		else
			m_mini->exec_status = 1;
	}
	else
		exec_cd1(str, data, m_mini);
	free(str);
}
