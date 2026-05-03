CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Bureaucrat.cpp AForm.cpp RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp PresidentialPardonForm.cpp
HEADER = Bureaucrat.hpp AForm.hpp RobotomyRequestForm.hpp \
	PresidentialPardonForm.hpp ShrubberyCreationForm.hpp
NAME =	TempleMethod
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