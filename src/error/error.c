/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:58:56 by ipetrov           #+#    #+#             */
/*   Updated: 2025/02/10 12:29:03 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// static char *get_msg(t_error error)
// {
// 	if (error == MALLOC)
// 		return ("malloc: allocation failed");
// 	else if (error == CMD_NOT_FOUND)
// 		return ("command not found");
// 	else if (error == FILE_NOT_FOUND)
// 		return ("No such file or directory");
// 	return ("");
// }
void	edup2(int oldfd, int newfd, t_node *node)
{
	if (dup2(oldfd, newfd) == ERROR)
		error(-1, node->ctx, (t_m){strerror(errno)});
}
pid_t	efork(t_node *node)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error(-1, node->ctx, (t_m){strerror(errno)});
	return (pid);
}

int	eopen(char *pathname, int flags, int mode, t_node *node)
{
	int	fd;

	fd = open(pathname, flags, mode, node);
	if (fd == ERROR)
	{
		free(pathname);
		error(-1, node->ctx, (t_m){strerror(errno)});
	}
	return (fd);
}

void	eexecve(char *pathname, t_node *node)
{
	int		exitcode;
	char	**argv;
	char	**envp;

	argv = node->ctx->stash;
	envp = node->ctx->envp;
	exitcode = node->ctx->exitcode;
	allclean(node, 0);
	if (!pathname)
		;
	else if (execve(pathname, argv, envp) == ERROR)
		error(-1, NULL, (t_m){strerror(errno)});
	free(pathname);
	ft_parrclean(&argv);
	ft_parrclean(&envp);
	exit(exitcode);
}

static	void	clean_tree(t_node *node)
{
	if (node == NULL)
		return ;
	clean_tree(node->left);
	clean_tree(node->right);
	free(node);
}

int	allclean(t_node *node, int mode)
{
	t_ctx	*ctx;
	int		exitcode;

	if (mode == 1)
	{
		ft_parrclean(&(node->ctx->envp));
		ft_parrclean(&(node->ctx->stash));
	}
	ctx = node->ctx;
	clean_tree(node->ctx->head);
	exitcode = ctx->exitcode;
	free(ctx);
	return (exitcode);
}

void error(int exitcode, t_ctx *ctx, t_m msg)
{
	puterr(PROGRAMM);
	while (*msg)
	{
		puterr(": ");
		if (*msg > (char *)TOK)
		{
			puterr("`");
			puterr(*msg - TOK);
			puterr("\'");
			msg++;
			continue ;
		}
		puterr(*msg);
		msg++;
	}
	puterr("\n");
	if (exitcode < 0)
	{
		allclean(ctx->head, FULL);
		exit(exitcode);
	}
	else
		ctx->exitcode = exitcode;
	return ;
}
