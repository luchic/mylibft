NAME = libft.a

# Mandatory part of the project
SRC_FIlES =		ft_atoi.c \
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
				ft_striteri.c

OBJ_FIlES = $(SRC_FIlES:.c=.o)

# Bounus part of the project
SRC_BONUS = 	ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Compiler and flags
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

$(NAME) : $(OBJ_FIlES)
	ar rcs $(NAME) $(OBJ_FIlES)

bonus : $(OBJ_FIlES) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_FIlES) $(OBJ_BONUS)

re : fclean all

fclean : clean
	rm -f $(NAME) 

clean : 
	rm -f $(OBJ_FIlES) $(OBJ_BONUS)

.PHONY: all clean fclean re bonus 