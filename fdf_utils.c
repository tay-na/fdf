
t_struct	*initialize(void)
{
	t_struct	*fdf;

	if (!(fdf = (t_struct *)ft_memalloc(sizeof(t_struct))))
		error(INIT);
	fdf->w = 0;
	fdf->h = 0;
	fdf->high = 1;
	fdf->step = 30;
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
	fdf->col = 0xFFFFFF;
	fdf->proj = 0;
	return (fdf);
}

void	erase_image(t_struct *fdf)
{
	int		i;

	i = 0;
	while (i < (HEIGHT * WIDTH - 1))
	{
		fdf->img_pix[i] = 0x000000;
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void		menu_window(t_struct *fdf)
{
	int		y;
	
	y = -1;
	fdf->col = 0xFFE185;
	while (y++ <= HEIGHT)
		put_pixel(fdf, MENU_W, y);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 200, 50, fdf->col, "How to use:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 100, fdf->col, "Move:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 150, fdf->col, "Left / Right: left arrow / right arrow");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 180, fdf->col, "Up / Down:    up arrow / down arrow");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 230, fdf->col, "Projection:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 280, fdf->col, "Change:		 NumPad 5");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 330, fdf->col, "Flatten:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 380, fdf->col, "More / Less:  NumPad 2 / NumPad 8");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 430, fdf->col, "Rotate Z-axis:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 480, fdf->col, "Left / Right: NumPad 7 / NumPad 9");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 530, fdf->col, "Rotate Y-axis:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 580, fdf->col, "Left / Right: NumPad 1 / NumPad 3");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 630, fdf->col, "Rotate X-axis:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 75, 680, fdf->col, "Left / Right: NumPad 0 / NumPad .");
}