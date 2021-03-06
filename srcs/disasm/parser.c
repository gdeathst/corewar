#include "disasm.h"

static uint8_t	*parse_code(int fd, size_t len)
{
	ssize_t	size;
	uint8_t	*buff;
	int8_t	check;

	buff = (uint8_t *)ft_memalloc(sizeof(int8_t) * len);
	if (!(buff))
		error("Malloc failure.");
	size = read(fd, buff, len);
	if (size == -1)
		error("Read failure.");
	if (size < (ssize_t)len || (read(fd, &check, 1) == -1))
		error("Invalid file.");
	return (buff);
}

static char	*parse_string(int fd, size_t len)
{
	ssize_t	size;
	char	*buff;

	buff = ft_strnew(len);
	if (!(buff))
		error("Malloc failure.");
	size = read(fd, buff, len);
	if (size == -1)
		error("Read failure.");
	if (size < (ssize_t)len)
		error("Invalid file.");
	return (buff);
}

static int32_t	parse_4bytes(int fd)
{
	ssize_t	size;
	uint8_t	val[4];

	size = read(fd, &val, 4);
	if (size == -1)
		error("Read failure.");
	if (size < 4)
		error("Invalid file.");
	return (bin_to_num(val, 4));
}

static void	check_filename(char *filename)
{
	char	**filename_parts;
	int		rows;

	filename_parts = ft_strsplit(filename, '.');
	if (!(filename_parts))
		error("Malloc failure.");
	rows = rows_count(filename_parts);
	if (rows < 2 || !ft_strequ(filename_parts[rows - 1], "cor"))
		error("Invalid extension.");
	ft_arrdel(&filename_parts);
}

void	parse_bin(t_bin *bin, char *file)
{
	int	fd;

	check_filename(file);
	bin->filename = ft_strdup(file);
	if (!(bin->filename))
		error("Malloc failure.");
	fd = open(file, O_RDONLY);
	if ((fd) == -1)
		error("Open failure.");
	if (parse_4bytes(fd) != COREWAR_EXEC_MAGIC)
		error("Invalid magic header.");
	bin->prog_name = parse_string(fd, PROG_NAME_LENGTH);
	if (parse_4bytes(fd) != 0)
		error("No null delimeter.");
	bin->prog_size = parse_4bytes(fd);
	bin->comment = parse_string(fd, COMMENT_LENGTH);
	if (parse_4bytes(fd) != 0)
		error("No null delimeter.");
	bin->code = parse_code(fd, bin->prog_size);
	close(fd);
}
