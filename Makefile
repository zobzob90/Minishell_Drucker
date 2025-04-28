NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -Iinc -Ilibft
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRCS = src/main.c \
       src/lexer/lexer.c \
	   src/lexer/lexer_init.c \
       src/lexer/lexer_utils.c \
       src/parsing/parsing.c \
       src/parsing/pars_utils.c \
       src/exec/exec.c \
       src/exec/exec_utils.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -L$(LIBFT_DIR) -lft -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
