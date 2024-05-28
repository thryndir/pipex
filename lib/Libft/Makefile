# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 18:19:52 by lgalloux          #+#    #+#              #
#    Updated: 2024/05/27 21:20:18 by lgalloux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
HEADER = -I../../include
NAME = libft.a

FT_FILES = ft_strlen ft_isprint ft_isalnum\
ft_isalpha ft_isdigit ft_memset ft_isascii ft_bzero\
ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper\
ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr\
ft_memcmp ft_strnstr ft_atolli ft_calloc ft_strdup\
ft_substr ft_strjoin ft_strtrim ft_split ft_itoa\
ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd\
ft_putendl_fd ft_putnbr_fd ft_lstsize ft_lstlast\
ft_lstnew ft_lstadd_front ft_lstadd_back ft_atoull\
ft_lstdelone ft_lstclear ft_lstiter ft_lstmap ft_putnbr\
ft_is_word_in ft_isspace ft_strcmp\

PF_FILES = ft_gestchar ft_gesthexa ft_gestint ft_printf

GNL_FILES = get_next_line get_next_line_utils

PF_DIR = printf/
GNL_DIR = gnl/
FT_DIR = libft/
OBJ_DIR = obj/

GNL_SRCS = $(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILES)))
GNL_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(GNL_FILES)))

PF_SRCS	= $(addprefix $(PF_DIR), $(addsuffix .c, $(PF_FILES)))
PF_OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(PF_FILES)))

FT_SRCS	= $(addprefix $(FT_DIR), $(addsuffix .c, $(FT_FILES)))
FT_OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FT_FILES)))

OBJS = $(GNL_OBJS) $(PF_OBJS) $(FT_OBJS)

all: $(NAME) 

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(GNL_DIR)%.c
	$(CC) $(HEADER) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o: $(PF_DIR)%.c
	$(CC) $(HEADER) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o: $(FT_DIR)%.c
	$(CC) $(HEADER) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re