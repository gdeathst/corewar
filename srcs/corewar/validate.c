#include "corewar.h"

static uint8_t	*parse_code(int fd, size_t len, t_game_params *p, int i)
{
	ssize_t	size;
	uint8_t	*buff;

	buff = (uint8_t *)ft_memalloc(sizeof(int8_t) * len);
	if (!(buff))
		error("Malloc failure.", p->players[i]->filename);
	size = read(fd, buff, len + 1);
	if (size == 0)
		error("champion has no code.", p->players[i]->filename);
	if (size == -1)
		error("Read failure.", p->players[i]->filename);
	if (size != (ssize_t)len)
		error("Header has invalid size.", p->players[i]->filename);
	return (buff);
}

static char	*parse_string(int fd, size_t len, t_game_params *p, int i)
{
	ssize_t	size;
	char	*buff;

	buff = ft_strnew(len);
	if (!(buff))
		error("Malloc failure.", p->players[i]->filename);
	size = read(fd, buff, len);
	if (size == -1)
		error("Read failure.", p->players[i]->filename);
	if (size < (ssize_t)len)
		error("Invalid file.", p->players[i]->filename);
	return (buff);
}

static int32_t	parse_4bytes(int fd, t_game_params *p, int i)
{
	ssize_t	size;
	uint8_t	val[4];

	size = read(fd, &val, 4);
	if (size == -1)
		error("Read failure.", p->players[i]->filename);
	if (size < 4)
		error("Invalid file.", p->players[i]->filename);
	return (bin_to_num(val, 4));
}

void	validate_players(t_game_params *p)
{
	int	fd;
	int	i;

	i = -1;
	while (p->players[++i])
	{
		get_fd(&fd, p, i);
		if (fd == -1)
			error("Open failure.", p->players[i]->filename);
		if (parse_4bytes(fd, p, i) != COREWAR_EXEC_MAGIC)
			error("Invalid magic header.", p->players[i]->filename);
		p->players[i]->name = parse_string(fd, PROG_NAME_LENGTH, p, i);
		if (parse_4bytes(fd, p, i) != 0)
			error("No null delimeter.", p->players[i]->filename);
		p->players[i]->code_size = parse_4bytes(fd, p, i);
		if (p->players[i]->code_size > CHAMP_MAX_SIZE
			|| !p->players[i]->code_size)
			error("Too big or zero code size.", p->players[i]->filename);
		p->players[i]->comment = parse_string(fd, COMMENT_LENGTH, p, i);
		if (parse_4bytes(fd, p, i) != 0)
			error("No null delimeter.", p->players[i]->filename);
		p->players[i]->code = \
			(char *)parse_code(fd, p->players[i]->code_size, p, i);
		close(fd);
	}
}
