GCC =       gcc -Wall -Wextra -Werror
NAME =      asm
FILES =     src/main.o src/cmds.o src/head.o src/label.o src/output.o

all: $(NAME)

$(NAME) : libft.a $(FILES)
	@ $(GCC) $(FILES) -o $(NAME) ./libft/libft.a
	@ echo "\033[32masm was compiled \033[0m"

libft.a:
	@ make -C ./libft

%.o: %.c
	@ gcc -o $@ -c $< -I . -I ./libft

clean:
	@ rm -rf $(FILES)
	@ make clean -C ./libft
	@ echo "\033[31mrm -rf *o\033[0m"


fclean: clean
	@ rm -rf $(NAME)
	@ rm -rf ./libft/libft.a

re: fclean all