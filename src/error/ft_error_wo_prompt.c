/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_wo_prompt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:33:52 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 05:53:29 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_error_wo_prompt(t_ms *ms, char *msg, char *str, int err_n)
{
	ft_reset_fd_in_out(ms);
	if (!str)
		ft_printf("%s\n", msg);
	else
		ft_printf("minishell: export: %s: %s\n", msg, str);
	g_exit_status = err_n;
	return (false);
}
