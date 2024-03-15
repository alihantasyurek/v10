/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:34:27 by emmodogl          #+#    #+#             */
/*   Updated: 2024/03/15 21:26:25 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
#define MESSAGE_H
#include "minishell.h"

# define W_ARGS "Error! Only needs program name.\n" 
# define A_ERR "Error! Allocation init error.\n"
# define ENV_ERR "Error! ENV Error\n"
# define EXEC 0
# define HEREDOC 1
# define PIPE 2
# define GREAT 3
# define GREATER 4
# define LESS 5
# define STDINN 0
# define STDOUT 1
# define STDERR 2

#endif
