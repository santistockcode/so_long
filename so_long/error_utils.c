void error_callback(int error, const char* description)
{
    ft_printf(stderr, "Error: %s\n", description);
}

static void ft_error_mlx(void)
{
	ft_printf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

