/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:21:37 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/15 20:04:06 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>

int	is_space(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (cmd[i] == '\0')
		return (0);
	return (1);
}

int	print_error(void)
{
	printf("%s\n", "minishell: syntax error near unexpected token");
	return (0);
}
