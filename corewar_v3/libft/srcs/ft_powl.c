long double	ft_powl(long double x, long double y)
{
	long double	n;

	n = 1;
	while (y--)
		n *= x;
	return (n);
}
