SRC_DIR = src 
TEMP_DIR = temp 
BIN_DIR = bin
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(TEMP_DIR)/%.o,$(SRCS))
OBJ_NAME = $(BIN_DIR)/Frogger

#Flags for linking
LINK_FLAGS =-lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -Wnarrowing -w -Wl,-subsystem,windows 

$(OBJ_NAME) : $(OBJS) 
	g++ -std=c++17 -g $(OBJS) -I$(INCLUDE_DIR) $(LINK_FLAGS) -o $(OBJ_NAME)

all : $(OBJ_NAME)

run: $(OBJ_NAME)
	$(OBJ_NAME)

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -std=c++17 -g -c $< -o $@ -I$(INCLUDE_DIR)

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJ_NAME)


	