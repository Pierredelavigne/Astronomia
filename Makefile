##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for my_rpg
##

# Default compiler
CC ?= gcc
RM ?= rm -f

# Project name
NAME = my_rpg
WINDOWS_NAME = $(NAME).exe

# Source files
SRC 	=	src/game/main.c \
			src/game/game.c \
			src/game/clean.c \
			src/game/menu.c \
			src/game/window.c \
			src/fights/fighting.c \
			src/fights/particle.c \
			src/fights/lp.c \
			src/fights/fight_tools.c \
			src/fights/set_fight.c \
			src/fights/event_fight.c \
			src/fights/clock.c \
			src/fights/win.c \
			src/fights/unset_fight.c \
			src/fights/lose.c \
			src/fights/set_two_fight.c \
			src/fights/snow.c \
			src/fights/init.c \
			src/map/load_map.c \
			src/map/map_sprites.c \
			src/map/map_tools.c \
			src/map/map_scene.c	\
			src/map/interactions.c \
			src/map/touch.c \
			src/map/free.c \
			src/map/draw.c \
			src/map/quest.c \
			src/map/music.c \
			src/map/init.c \
			src/inventory/linked_list_tools.c \
			src/inventory/inventory_menu.c \
			src/inventory/inventory_tools.c \
			src/inventory/set_inventory.c \
			src/inventory/inventory_get.c \
			src/inventory/update_inventory.c \
			src/tools/mouse.c \
			src/character/hero.c \
			src/character/hero_moves.c \
			src/character/hero_collide.c \
			src/character/npc.c \
			src/character/trader.c \
			src/character/thief.c \
			src/cinematic/starting_game.c \
			src/cinematic/cinematic.c \
			src/cinematic/events.c \
			src/cinematic/movements.c \
			src/cinematic/texts.c \
			src/cinematic/free.c \
			src/cinematic/sprites.c \
			src/cinematic/music.c \
			src/stats/stats.c \
			src/camera/camera.c \
			src/scenes/click.c \
			src/scenes/how_to_play.c \
			src/scenes/init.c \
			src/scenes/scene_pause.c \
			src/scenes/scene_menu.c \
			src/cinematic_end/loop.c \
			src/cinematic_end/init.c \
			src/cinematic_end/draw.c

OBJ = $(SRC:.c=.o)

# Common flags
COMMON_CFLAGS = -Wall -Wextra -Iinclude
LIBMY_DIR = lib/my
LIBMY_A = $(LIBMY_DIR)/libmy.a

# Platform detection (simple version)
# To compile for Windows, use: make PLATFORM=WINDOWS
# Or set OS environment variable (Windows_NT for cmd/powershell, MINGW for MSYS2/Git Bash)
ifeq ($(OS),Windows_NT)
	PLATFORM = WINDOWS
else ifneq (,$(findstring MINGW,$(shell uname -s)))
	PLATFORM = WINDOWS
else ifneq (,$(findstring CYGWIN,$(shell uname -s)))
	PLATFORM = WINDOWS
else
	PLATFORM = LINUX
endif

# Default SFML/CSFML paths for Windows - User should override if necessary
# Example: make PLATFORM=WINDOWS SFML_PATH=C:/your/path/to/SFML CSFML_PATH=C:/your/path/to/CSFML
SFML_PATH ?= C:/SFML
CSFML_PATH ?= C:/CSFML # Can be the same as SFML_PATH if merged

ifeq ($(PLATFORM),WINDOWS)
	TARGET_NAME = $(WINDOWS_NAME)
	# MinGW typically uses gcc
	# CC = x86_64-w64-mingw32-gcc # Or simply gcc if in MinGW env path
	CFLAGS = $(COMMON_CFLAGS) -I$(CSFML_PATH)/include -I$(SFML_PATH)/include
	# For MinGW, -mwindows can be used for GUI apps to suppress console, but only if WinMain is entry point.
	# This project uses main(), so console will appear.
	LDFLAGS = -L$(CSFML_PATH)/lib -L$(SFML_PATH)/lib -L$(LIBMY_DIR)
	# Order of libs can be important. CSFML, then SFML, then dependencies.
	# -lsfml-main is often needed for MinGW GUI apps linked with GCC.
	LIBS = -lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system \
	       -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lsfml-main \
	       -lopengl32 -lfreetype -lopenal32 -lgdi32 -lwinmm
	# Command to copy DLLs (SFML + dependencies like openal32.dll, libfreetype-6.dll)
	# Assumes DLLs are in SFML_PATH/bin
	COPY_DLLS = cp $(SFML_PATH)/bin/*.dll . || echo "DLLs not found or copy failed, please ensure SFML DLLs are in $(SFML_PATH)/bin"
	RM = del /Q /F # Windows delete command for .o files and executable
	OBJ_EXT = .o # MinGW uses .o
else # Linux (default)
	TARGET_NAME = $(NAME)
	CFLAGS = $(COMMON_CFLAGS) -fpic -I/usr/local/include # Add /usr/local/include for CSFML if installed there
	LDFLAGS = -L/usr/local/lib -L$(LIBMY_DIR) # Add /usr/local/lib for CSFML
	LIBS = -lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system
	COPY_DLLS = @# No DLLs to copy on Linux typically
	RM = rm -f
	OBJ_EXT = .o
endif

# Ensure OBJ uses the correct extension (though .o is common)
OBJ := $(SRC:.c=$(OBJ_EXT))

all: $(TARGET_NAME)

$(LIBMY_A):
	@echo "--- Compiling libmy for $(PLATFORM) ---"
	$(MAKE) -C $(LIBMY_DIR) CC='$(CC)' AR='$(AR)' RM='$(RM)' PLATFORM=$(PLATFORM)

$(TARGET_NAME): $(OBJ) $(LIBMY_A)
	@echo "--- Linking $(TARGET_NAME) ---"
	$(CC) $(CFLAGS) -o $(TARGET_NAME) $(OBJ) $(LDFLAGS) $(LIBS)
	@echo "--- $(TARGET_NAME) built successfully ---"
	$(COPY_DLLS)
	@echo "--- DLLs processed (if any for Windows) ---"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBMY_DIR) RM='$(RM)' clean

fclean:
	$(RM) $(OBJ)
	$(RM) $(TARGET_NAME)
	$(MAKE) -C $(LIBMY_DIR) RM='$(RM)' fclean
	@if exist *.dll ( del /Q /F *.dll ) else ( echo "No DLLs to clean in current directory." )

re: fclean all

.PHONY: all clean fclean re
