#include "asm.h"

static char	*get_buffer(t_exec *info, int fd)
{
	char	*buf;
	int		i;

	i = -1;
	buf = (char *)malloc(sizeof(char) * (++i + 1));
	if (!buf)
		terminate(info, 0, NULL);
	while (read(fd, &buf[i], 1) == 1)
	{
		buf = (char *)ft_reallocf(buf, sizeof(char) * (++i + 1));
		if (!buf)
			terminate(info, 0, NULL);
	}
	buf[i] = '\0';
	return (buf);
}

void	get_file_contents(t_exec *info)
{
	int	fd;

	fd = open(info->path, O_RDONLY);
	if (read(fd, NULL, 0) == -1)
		terminate(info, 1, NULL);
	info->buf = get_buffer(info, fd);
	close(fd);
}
