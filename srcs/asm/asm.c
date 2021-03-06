#include "asm.h"

static void	print_usage(char *name)
{
	ft_printf("Usage: %s [-a] <sourcefile.s>\n", name);
	ft_printf("    -a : Instead of creating a .cor file, outputs a stripped "
		"and annotated version of the code to the standard output\n");
}

void	assembler(char **input)
{
	t_exec	info;

	get_options(&info, input);
	get_file_contents(&info);
	lex_corewar(&info);
	parse_tokens(&info);
	parse_lines(&info);
	if (info.option)
		annotated_output(&info);
	else
		bytecode_output(&info);
	destroy_struct(&info);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		assembler(argv);
	else
		print_usage(argv[0]);
	exit(EXIT_SUCCESS);
}
