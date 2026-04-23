CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Bureuacrat.cpp
HEADER = Bureuacrat.hpp
NAME =	Bureuacrat
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all