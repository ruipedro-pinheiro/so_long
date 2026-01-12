/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:18:16 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/09 17:04:30 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
#include <stdbool.h>

int	map_generator(void)
{
	return (0);
}
bool	string_check(char *string)
{
	if (ft_strchr(string, 'Y') != '\0' || ft_strchr(string, 'Y'))
		return (true);
	if (ft_strnstr(string, "YES", ft_strlen(string)))
		return (true);
	return (false);
}
int	main(void)
{
	char	**input;

	ft_printf("Do you want a valid map ? Say no for debug or test purposes");
	read(0, input, 8);
	string_check(*input);
	map_generator();
}
