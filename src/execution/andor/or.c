/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:09:28 by ipetrov           #+#    #+#             */
/*   Updated: 2025/02/09 10:07:13 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	process_or(t_node	*node)
{
	evaluate(node->left);
	if (node->ctx->exitcode != EXIT_SUCCESS)
	{
		evaluate(node->right);
		run_cmd(node);
		//set $? using node->ctx->exitcode use export builtin for that
	}
	return ;
}
