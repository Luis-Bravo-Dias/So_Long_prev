/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:35:24 by lleiria-          #+#    #+#             */
/*   Updated: 2022/04/04 17:24:46 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/longlib.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	mlx_clear_window(program->mlx, program->window.reference);
	if (key == 2)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 0)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 1)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 13)
		program->sprite_position.y -= program->sprite.size.y;
}

int ft_close()
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;
	
	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.x = height;

	
	return (window);
}

/*
//saber o codigo da tecla
int	key(int keycode)
{
	ft_printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Soul Catcher");
	img.img = mlx_new_image(mlx, 1920, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key, NULL);//saber o codigo da tecla
	mlx_loop(mlx);
}
*/