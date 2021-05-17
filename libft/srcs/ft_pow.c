double	ft_pow(double x, double y)
{
	double	n;

	n = 1;
	while (y--)
		n *= x;
	return (n);
}
