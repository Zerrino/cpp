# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 22:30:05 by alexafer          #+#    #+#              #
#    Updated: 2024/06/26 13:34:27 by alexafer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CXX = c++
CXXFLAGS = -std=c++98 #-Wall -Wextra -Werror

OBJ_DIR = .objs

TARGET = Harl

MAIN = main

FILES = Harl

SOURCES = $(MAIN:=.cpp) $(FILES:=.cpp)

HEADER  = $(FILES:=.hpp)

OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJECTS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

$(OBJ_DIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

