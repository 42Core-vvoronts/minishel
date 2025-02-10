/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:00:41 by vvoronts          #+#    #+#             */
/*   Updated: 2025/02/10 19:07:11 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_word_lexeme(char *lexeme)
{
    if (ft_isalpha(*lexeme) || ft_isdigit(*lexeme) || 
        *lexeme == '_' || *lexeme == '-' || *lexeme == '.')
        return true;
    return false;
}

void	tokenize_words(char **lexeme, t_tok **tokens, t_tok **current)
{
	char	*start;
	char	*end;
	t_tok	*new;

	start = *lexeme;
	end = start;
	new = NULL;
	if (!*lexeme)
		error_exit("end of statement");
	if (!is_word_lexeme(*lexeme))
		return ;
	start = *lexeme;
	end = start;
	while (*end && is_word_lexeme(end))
		end++;
	new = init_token(start, end - start);
	add_token(new, tokens, current);
	*lexeme = end;
}
