/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:21:23 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/17 01:02:50 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

bool	is_numeric(char *s)
{
	while ((9 <= *s && *s <= 13) || *s == 32)
		s++;
	if (*s == 43 || *s == 45)
		s++;
	while (48 <= *s && *s <= 57)
		s++;
	while ((9 <= *s && *s <= 13) || *s == 32)
		s++;
	if (*s != '\0')
		return (false);
	return (true);
}

void	builtin_exit(t_mini **m_mini)
{
	bool	status;
	int		exit_value;

	exit_value = 0;
	printf("exit\n");
	if (!(*m_mini)->parse->text || (*m_mini)->parse->type != '\0')
		exit(EXIT_SUCCESS);
	status = is_numeric((*m_mini)->parse->text[0]);
	if (status == false)
	{
		printf("bash: exit: %s: numeric argument required\n",
			(*m_mini)->parse->text[0]);
		exit_value = 255; ///doru
	}
	else if (status == true && !(*m_mini)->parse->text[1])
		exit_value = ft_atoi((*m_mini)->parse->text[0]);
	else
	{
		printf("bash: exit: too many arguments\n");
		(*m_mini)->exec_status = 1; ///doru
		return ;
	}
	(free_loop(1, *m_mini), free_(*m_mini));
	(free((*m_mini)->lex_list), free(*m_mini));
	exit(exit_value);
}
