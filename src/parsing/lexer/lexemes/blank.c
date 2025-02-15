/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blanks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:11:12 by vvoronts          #+#    #+#             */
/*   Updated: 2025/02/12 11:50:20 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool is_blank(char *lexeme)
{
    if (lexeme && (is_eqlchar(*lexeme, ' ') || 
		is_eqlchar(*lexeme, '\t') || is_eqlchar(*lexeme, '\n')))
        return true;
    return false;
}

void	skip_blanks(char **lexeme)
{
	while (is_blank(*lexeme))
		(*lexeme)++;
}


