# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 13:35:53 by nluchini          #+#    #+#              #
#    Updated: 2025/07/29 13:29:58 by nluchini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Mandatory part of the project

# Src
SRC = src
CORE = core

LIBFT_CORE_FILES =	ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_islower.c \
					ft_isupper.c \
					ft_itoa.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_min.c \
					ft_max.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_putnstr_fd.c \
					ft_putlnbr_fd.c \
					ft_putlnbr_base_fd.c\
					ft_putulnbr_base_fd.c\
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
					ft_lstsize_bonus.c

# Core library
CORE_FIlES = $(addprefix $(SRC)/$(CORE)/, $(LIBFT_CORE_FILES))
CORE_OBJ_FIlES = $(CORE_FIlES:.c=.o)

#Include
HEADER = includes

# Compiler and flags
CFLAGS = -Wall -Wextra -Werror -I$(HEADER) 
CC = cc

all : $(NAME)

$(NAME) : $(CORE_OBJ_FIlES)
	ar rcs $(NAME) $(CORE_OBJ_FIlES)

%.o : %.c
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

re : fclean all

fclean : clean
	rm -f $(NAME) 

clean : 
	rm -f $(CORE_OBJ_FIlES)

.PHONY: all clean fclean re 