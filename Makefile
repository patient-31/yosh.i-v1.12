# Define the target executable
TARGET := yosh.i

# Define the compiler and flags
C_COMPILER 			:= gcc
LDFLAGS 			:= -lreadline -L/opt/homebrew/Cellar/readline/8.2.13/lib # alter this path if on linux
INCLUDE_PATH_RL	   	:= -I/opt/homebrew/Cellar/readline/8.2.13/include # alter this path if on linux
FLAGS 				:= -Wextra -Werror -Wall
ADDSAN 				:= -fsanitize=address -g

# Define source and object directories
SRC_DIR := source/
OBJ_DIR := object/

# Find all .c files in the source directory
SOURCE := $(wildcard $(SRC_DIR)*.c)

# Convert source files to object files
OBJECTS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCE))

# Linking command
LINK := $(C_COMPILER) $(FLAGS) $(ADDSAN) -o $(TARGET) $(OBJECTS) $(CFLAGS) $(LDFLAGS) $(INCLUDE_PATH_RL)


test: all


# Default rule to build the target executable
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ_DIR) $(OBJECTS)
	echo "CREATING EXECUTABLE..."
	$(LINK)

# Rule to compile source files into object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "COMPILING OBJECTS ($@)"
	$(C_COMPILER) $(FLAGS) $(ADDSAN) -c $< -o $@ $(CFLAGS)

# Rule to create the object directory
$(OBJ_DIR):
	echo "CREATING OBJECT DIRECTORY..."
	mkdir -p $(OBJ_DIR)

# Rule to clean up compiled files
clean:
	echo "REMOVING OBJECT FILES..."
	rm -rf $(OBJ_DIR) $(TARGET)

help:
	echo "Usage:"
	echo "  make [target]"
	echo ""
	echo "  help          Display this help message"


# Phony targets
.PHONY: clean all help
.SILENT: