
SRC =	src/ft_bzero.c \
	src/ft_memcpy.c \
	src/ft_split.c \
	src/ft_strdup.c \
	src/ft_strjoin.c \
	src/ft_strlen.c \
	src/ft_strnstr.c \
	src/ft_strtrim.c \
	src/ft_substr.c \
	src/pipex.c \
	src/utils.c\
	src/utils2.c

OBJ = $(SRC:.c=.o)
NAME = pipex
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
CC = cc

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(OBJ) : %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
.SECONDARY: $(OBJ)
