/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:48:11 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/04 11:39:02 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *ft_capitalize(char *str)
{
    int i;
    char *new_str;

    i = 0;
    new_str = ft_calloc(ft_strlen(str) + 1, sizeof(char));
    while(i < (int)ft_strlen(str))
    {
        new_str[i] = ft_toupper(str[i]);
        i++;
    }
    return (new_str);
}