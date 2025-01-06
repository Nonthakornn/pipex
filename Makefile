NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT_DIR = libft
LIBFT_LIB = libft/libft.a
IFLAGS = -I$(LIBFT_DIR) 

SRCS_FILES = src/pipex.c src/parse.c src/process.c src/utils.c
OBJ_FILES = $(SRCS_FILES:.c=.o)

BLUE = \033[34m
RESET = \033[0m

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			@make -C $(LIBFT_DIR)
			@echo "$(BLUE)libft Success$(RESET)"
			$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_LIB) -o $(NAME)
			@echo "$(BLUE)Pipex Success$(RESET)"

%.o:		%.c
			@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
			@make clean -C $(LIBFT_DIR)	
			@$(RM) ${OBJ_FILES}
			@echo "$(BLUE)Clean Success$(RESET)"

fclean:		clean
			@make fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)
			@echo "$(BLUE)FClean Success$(RESET)"

re:			fclean all

.PHONY:		libft clean fclean re