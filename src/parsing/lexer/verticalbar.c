/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verticalbar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:00:33 by vvoronts          #+#    #+#             */
/*   Updated: 2025/02/10 19:28:01 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_vertical_bar(char *lexeme)
{
    if (is_eqlchar(*lexeme, '|'))
        return true;
    return false;
}

void	tokenize_vertical_bar(char **lexeme, t_tok **tokens, t_tok **current)
{
	char	*start;
	char	*end;
	t_tok	*new;

	start = *lexeme;
	end = start;
	new = NULL;
	if (is_vertical_bar(end + 1))
		end++;
	new = init_token(start, end - start + 1);
	add_token(new, tokens, current);
	*lexeme = end + 1;
	if (is_operator(*lexeme))
		error_exit("syntax error near unexpected token");
}
