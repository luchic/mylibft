# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 13:35:53 by nluchini          #+#    #+#              #
#    Updated: 2025/07/09 09:04:29 by nluchini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# All files with a bonus suffix
SRC_ALL_FILES = ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_striteri.c \
				ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c \

OBJ_ALL_FILES = $(SRC_ALL_FILES:.c=.o)

# Mandatory part of the project
SRC_FIlES = $(filter-out *_bonus.c, $(SRC_ALL_FILES))
OBJ_FIlES = $(SRC_FIlES:.c=.o)



# Compiler and flags
CC_FLAGS = -Wall -Wextra -Werror
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
	rm -f $(OBJ_ALL_FILES)

.PHONY: all clean fclean re bonus # clean_debug debug