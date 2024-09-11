NAME	= pipex
CC 	= cc
CFLAGS	= -Wextra -Wall -Werror -g
HEADER = -Ilib/Libft/include -Iinclude
LIB	= lib/Libft/libft.a

FILES = main init init_exec exec utils error

SRC_DIR = src/
OBJ_DIR = obj/

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

$(LIB):
	make -C lib/Libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	make fclean -C lib/Libft

re: fclean all

.PHONY: all, clean, fclean, re
