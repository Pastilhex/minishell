/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/17 14:34:41 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_exit(t_ms *ms)
{
	if(ms->n_pipes == 0)
	{
		ft_printf("exit\n");
		ft_free_env(ms);
		ft_free_array(ms->paths);
		if (ms->cmds[0].args[1])
			exit(ft_atoi(ms->cmds[0].args[1]));
	}
	exit(g_exit_status);
}
