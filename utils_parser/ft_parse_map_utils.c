/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:22:38 by rluari            #+#    #+#             */
/*   Updated: 2024/03/05 19:58:59 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

_Bool	ft_ends_with_cub(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (str[len - 1] == 'b' && str[len - 2] == 'u'
		&& str[len - 3] == 'c' && str[len - 4] == '.'
		&& str[len - 5] != '/')
		return (1);
	return (0);
}

_Bool	ft_correct_map_line(char *str)
{
	while (*str && *str != '\n')
	{
		if (*str != ' ' && *str != '1' && *str != '0' && *str != 'N'
			&& *str != 'E' && *str != 'W' && *str != 'S')
			return (ft_putstr_fd("Error\nInvalid map line\n", 2), 0);
		str++;
	}
	return (1);
}

_Bool	ft_starts_with_number(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (ft_isdigit(*str))
		return (1);
	return (0);
}

void	ft_skip_spaces(char **str)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
}
