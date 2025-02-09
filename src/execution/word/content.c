/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:08:11 by ipetrov           #+#    #+#             */
/*   Updated: 2025/02/09 10:09:53 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	process_content(t_node *node)
{
	//expand $var and expand *
	add_arg(ft_strdup(node->token), node);
	evaluate(node->right);
}