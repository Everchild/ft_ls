# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/12 18:59:52 by sbrochar          #+#    #+#              #
#    Updated: 2017/05/15 16:31:14 by sbrochar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

INC = $(INC_DIR)/libft.h
SRC = buff_handler.c \
	  \
	  pf_main.c \
	  pf_formating_string.c \
	  pf_get_specs.c \
	  pf_get_conversion.c \
	  pf_convert_specs.c \
	  pf_get_type1.c \
	  pf_get_type2.c \
	  pf_get_type3.c \
	  pf_get_type4.c \
	  pf_apply_precision.c \
	  pf_apply_opt1.c \
	  pf_apply_opt2.c \
	  pf_apply_opt3.c \
	  \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  \
	  create_list.c \
	  create_node.c \
	  add_node_end.c \
	  add_node_start.c \
	  swap_nodes.c \
	  remove_node.c \
	  free_list.c \
	  iter_list.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_memdup.c \
	  ft_realloc.c \
	  \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strndup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_strpos.c \
	  ft_strnpos.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strcjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_strrev.c \
	  ft_wstrlen.c \
	  ft_itoa_base.c \
	  ft_strupper.c \
	  ft_strjoinf.c \
	  ft_wctombc.c \
	  \
	  ft_tabdup.c \
	  \
	  ft_abs.c \
	  ft_pow.c \
	  \
	  ft_exit.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  \
	  get_next_line.c
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -I$(INC_DIR)
LD = ar rcs

$(NAME): $(OBJ)
	$(LD) $@ $^

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
