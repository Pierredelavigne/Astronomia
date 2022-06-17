##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile of stumper 3
##

NAME 	=	my_rpg

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


OBJ		=	$(SRC:.c=.o)

CFLAGS 	=	-I include -fpic -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

LIB = -L lib/my -l my

all	: $(NAME)

$(NAME)	:	$(OBJ)
	make -C lib/my/
	gcc -Wall -Wextra -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean	:
	rm -f $(OBJ)
	make clean -C lib/my/

fclean	:	clean
	rm -f $(NAME)
	make fclean -C lib/my/

re	: fclean all
