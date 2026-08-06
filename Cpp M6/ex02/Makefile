CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
SRC = Main.cpp Base.cpp A.cpp B.cpp C.cpp
HEADER = A.hpp B.hpp C.hpp Base.hpp
NAME = realType
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