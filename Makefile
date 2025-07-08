# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 13:35:53 by nluchini          #+#    #+#              #
#    Updated: 2025/07/08 15:05:51 by nluchini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# All files with a bonus suffix
SRC_ALL_FILES = $(wildcard *.c)
OBJ_ALL_FILES = $(SRC_ALL_FILES:.c=.o)

# Mandatory part of the project
SRC_FIlES = $(filter-out *_bonus.c, $(SRC_ALL_FILES))
OBJ_FIlES = $(SRC_FIlES:.c=.o)



# Compiler and flags
CC_FLAGS = -Wall -Wextra -Werror -std=c99
CC = cc

# Tests
# TEST_NAME = test.out

# SRC_TESTS = $(wildcard tests/*.c)
# OBJ_TESTS = $(SRC_TESTS:.c=.o)

all : $(OBJ_FIlES)
	ar rcs $(NAME) $(OBJ_FIlES)

$(NAME) : $(OBJ_FIlES)
	ar rcs $(NAME) $(OBJ_FIlES)

bonus : $(OBJ_ALL_FILES)
	ar rcs $(NAME) $(OBJ_ALL_FILES)

# debug : $(SRC_TESTS) $(SRC_FIlES)
# 	$(CC) -g $^ -o $(TEST_NAME)


%.o : %.c
	$(CC) $(CC_FLAGS) -o $@ -c $<


re : fclean all

# clean_debug: fclean
# 	rm -fr $(TEST_NAME).dSYM
# 	rm -f $(TEST_NAME)

fclean : clean
	rm -f $(NAME) 

clean : 
	rm -f $(OBJ_FIlES)

.PHONY: all clean fclean re bonus # clean_debug debug