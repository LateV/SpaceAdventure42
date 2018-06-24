NAME = ft_retro

SRC =	main.cpp         		\
		player.cpp         		\
		Game.cpp 				\
		Window.cpp 				\
		bullet.cpp 				\
		Foe.cpp 				\


OBJ = $(SRC:.cpp=.o)

CC = clang++

CFLAGS = -Wall -Wextra -Werror -lncurses

all: $(NAME) 

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all 