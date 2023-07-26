/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmd_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:49:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 19:51:29 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_command_nodes(t_ms *ms, int n_pipes)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	printf("\n|--------> PRINTANDO COMANDOS <---------|\n|");
	while (i < (n_pipes * 2 + 1))
	{
		ft_print_command_nodes_while_pipe(ms, i, j, k);
		k = 0;
		i++;
	}
	printf("\n|---------------------------------------|\n");
}
