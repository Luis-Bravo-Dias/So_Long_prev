/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:31 by lleiria-          #+#    #+#             */
/*   Updated: 2022/04/04 16:15:53 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONGLIB_H
# define LONGLIB_H
# include <mlx.h>

# include "../ft_printf/ft_printf.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}	t_window;

typedef struct s_program
{
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}	t_program;
/*
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif