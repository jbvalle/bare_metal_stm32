##############
## Binaries ##
##############
CC = arm-none-eabi-gcc

###################
## Arch Specific ##
###################
MARCH  = cortex-m4

#################
## Directories ##
#################
SRC_D = src
OBJ_D = obj
INC_D = inc
STARTUP_D  = startup
DEBUG_D = debug

#######################
## Src and Obj Files ##
#######################
SRC  = $(wildcard $(SRC_D)/*.c)
SRC += $(wildcard $(STARTUP_D)/*.c)

OBJ := $(patsubst $(SRC_D)/%.c, $(SRC_D)/$(OBJ_D)/%.o, $(SRC))
OBJ := $(patsubst $(STARTUP_D)/%.c, $(SRC_D)/$(OBJ_D)/%.o, $(OBJ))

LS   = $(wildcard $(STARTUP_D)/*.ld)


####################
## Compiler Flags ##
####################
ARCHFLAGS = -mcpu=$(MARCH) -mthumb
CFLAGS = -g -O0 -Wall -Wextra -std=gnu11 -I./$(INC_D)
LFLAGS = -nostdlib -T $(LS) -Wl,-Map=./$(DEBUG_D)/main.map 

#############
## Targets ##
#############
TARGET = $(DEBUG_D)/main.elf

all: $(OBJ) $(TARGET)

# Create Object files from src files
$(SRC_D)/$(OBJ_D)/%.o : $(SRC_D)/%.c | mk_obj_d
	$(CC) $(ARCHFLAGS) $(CFLAGS) -c -o $@ $^

# Create Object file from startup file
$(SRC_D)/$(OBJ_D)/%.o : $(STARTUP_D)/%.c | mk_obj_d
	$(CC) $(ARCHFLAGS) $(CFLAGS) -c -o $@ $^

# Create ELF File
$(TARGET) : $(OBJ) | mk_debug_d
	$(CC) $(LFLAGS) -o $@ $^

mk_obj_d:
	mkdir -p $(SRC_D)/$(OBJ_D)

mk_debug_d:
	mkdir -p $(DEBUG_D)

clean:
	rm -rf $(SRC_D)/$(OBJ_D) $(TARGET)

.PHONY = mk_obj_d mk_debug_d clean
