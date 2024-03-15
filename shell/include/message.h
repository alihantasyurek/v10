/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:34:27 by emmodogl          #+#    #+#             */
/*   Updated: 2024/03/15 20:35:33 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
#define MESSAGE_H
#include "minishell.h"

# define W_ARGS "Error! Only needs program name.\n" // fixed the message
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
