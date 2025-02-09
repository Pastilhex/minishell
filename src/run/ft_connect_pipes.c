/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 23:48:52 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_connect_pipes(t_ms *ms, t_counters *c)
{
	if (ms->cmds[c->i + 1].type == PIPE_LINE)
	{
		if (ms->cmds[c->i].out == 1)
		{
			ms->cmds[c->i].out = dup(ms->cmds[c->i + 1].fd[1]);
			close(ms->cmds[c->i + 1].fd[1]);
		}
		else
			close(ms->cmds[c->i + 1].fd[1]);
	}
	if (c->i > 0 && ms->cmds[c->i - 1].type == PIPE_LINE)
	{
		if (ms->cmds[c->i].in == 0)
		{
			ms->cmds[c->i].in = dup(ms->cmds[c->i - 1].fd[0]);
			close(ms->cmds[c->i - 1].fd[0]);
		}
		else
		{
			close(ms->cmds[c->i - 1].fd[0]);
			close(ms->cmds[c->i - 1].fd[1]);
		}
	}
}
