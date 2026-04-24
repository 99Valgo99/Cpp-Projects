CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Bureaucrat.cpp
HEADER = Bureaucrat.hpp
NAME =	Bureaucrat
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@
# asm:
#	$(CXX) $(CXXFLAGS) -S -fverbose-asm Bureaucrat.cpp -o Bureaucrat.s

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all