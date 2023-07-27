##
## EPITECH PROJECT, 2023
## B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
## File description:
## Makefile
##

CXX			=	g++ -std=c++17 \
				-I./sources/abstract \
				-I./sources/interfaces \
				-I./sources/material \
				-I./sources/math \
				-I./sources/primitives \
				-I./sources/utils \

CXXFLAGS	=	-Wall -Wextra -floop-parallelize-all -g3

LDFLAGS		=	-lconfig++

SRC			=	$(shell find -name "*.cpp")

OBJ			=	$(SRC:.cpp=.o)

BIN			=	raytracer

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)
	$(RM) *.ppm

re: fclean all
