
SRC = ft_bzero.c \
      ft_memcpy.c \
      ft_split.c \
      ft_strdup.c \
      ft_strjoin.c \
      ft_strlen.c \
      ft_strnstr.c \
      ft_strtrim.c \
      ft_substr.c \
      pipex.c \
      utils.c\
      utils2.c

OBJ = $(SRC:.c=.o)
NAME = pipex
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(OBJ) : %.o : %.c
	$(CC) $(CFLAGS) -c $<
.SECONDARY: $(OBJ)