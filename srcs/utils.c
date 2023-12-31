/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:51:59 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/29 15:09:36 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	freetab(t_data *data, size_t high, int boolean, char *mess)
{
	size_t	i;

	i = 0;
	while (i < high)
	{
		free(data->map.layout[i]);
		data->map.layout[i] = NULL;
		i++;
	}
	free(data->map.layout);
	data->map.layout = NULL;
	if (boolean == 1)
		error_message(mess);
	return (-1);
}

size_t	strlen_map(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	error_message(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	write(1, "Error\n", 7);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (-1);
}

int	put_image(t_data *data, void *xpm, size_t x, size_t y)
{
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, xpm, (int)x, (int)y);
	return (1);
}
