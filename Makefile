NAME=game
SDL_PATH=./sdl

SRC_NAME=main.cpp\
		 display.cpp

SRC=$(addprefix srcs/, $(SRC_NAME))
OBJ=$(patsubst srcs/%.cpp, obj/%.o, $(SRC))

OBJ_DIR=obj

CC=g++
INC=-I includes -I $(SDL_PATH)/include/SDL2
SDL=-L $(SDL_PATH)/lib -l SDL2-2.0.0
CFLAGS=-g $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(SDL)
	@echo "Compile the game"

obj/%.o: srcs/%.cpp
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all
