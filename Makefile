NAME		= miniRT
FOLDER		= src/
SRC			= \
amb.c \
cam.c \
close_mrt.c \
color.c \
color_uts.c \
compute_light.c \
cone.c \
cy.c \
cy_rt.c \
draw.c \
errors.c \
ft_atox.c \
ft_exit.c \
hud.c \
keyhook1.c \
keyhook2.c \
keyhook3.c \
keyhook_cammove.c \
lib1.c \
lib2.c \
light.c \
minirt.c \
mousehook.c \
new_img.c \
parse_uts.c \
plane1.c \
plane2.c \
quaternion.c \
render_next_fr.c \
render_next_fr_uts1.c \
render_next_fr_uts2.c \
scene_init.c \
sph.c \
toggle.c \
vector3_1.c \
vector3_2.c \
vector3_3.c \
vector3_4.c \
views1.c \
views2.c \

SRC_BON1 := $(patsubst minirt.c, minirt_bon.c, $(SRC))
SRC_BON2 := $(patsubst render_next_fr.c, render_next_fr_bon.c, $(SRC_BON1))
SRC_BON3 := $(patsubst hud.c, hud_bon.c, $(SRC_BON2))
SRC_BON := $(SRC_BON3) mtv_bon.c

HDR := minirt.h
HDR_BON := minirt_bon.h

OBJS := $(addprefix $(FOLDER), $(SRC:%.c=%.o))
OBJS_BON := $(addprefix $(FOLDER), $(SRC_BON:%.c=%_bonus.o))
HDRS := $(addprefix $(FOLDER), $(HDR))
HDRS_BON := $(addprefix $(FOLDER), $(HDR_BON))

CC := cc
CFLAGS := -Wall -Wextra -Werror

RM := rm -rf

MLX := libmlx.a
MLX_PATH := mlx_static/
MLX_FLAGS := -framework OpenGL -framework AppKit

LIBKD := libft.a
LIBKD_PATH := libkd/

GNL := libgnl.a
GNL_PATH := gnl/

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %.c $(HDRS) $(HDRS_BON)
	$(CC) $(CFLAGS) -D BONUS=1 -c $< -o $@

$(NAME): all

all: mlx libkd gnl .main

bonus: mlx libkd gnl .bonus

mlx:
	@echo "Making $(MLX_PATH)$(MLX)"
	@make -C $(MLX_PATH)

libkd:
	@echo "Making $(LIBKD_PATH)$(LIBKD)"
	@make -C $(LIBKD_PATH)

gnl:
	@echo "Making $(GNL_PATH)$(GNL)"
	@make -C $(GNL_PATH)

.main: $(OBJS) $(MLX_PATH)$(MLX) $(LIBKD_PATH)$(LIBKD) $(GNL_PATH)$(GNL)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_PATH)$(MLX) $(MLX_FLAGS) $(LIBKD_PATH)$(LIBKD) $(GNL_PATH)$(GNL)
	@touch .main
	@$(RM) .bonus

.bonus: $(OBJS_BON) $(MLX_PATH)$(MLX) $(LIBKD_PATH)$(LIBKD) $(GNL_PATH)$(GNL)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BON) $(MLX_PATH)$(MLX) $(MLX_FLAGS) $(LIBKD_PATH)$(LIBKD) $(GNL_PATH)$(GNL)
	@touch .bonus
	@$(RM) .main

clean:
	@$(RM) $(OBJS) $(OBJS_BON)
	@echo "clean is finished"

mlx_clean:
	@make clean -C $(MLX_PATH) > /dev/null
	@echo "mlx_clean is finished"

libkd_clean:
	@make clean -C $(LIBKD_PATH) > /dev/null
	@echo "libkd_clean is finished"

gnl_clean:
	@make clean -C $(GNL_PATH) > /dev/null
	@echo "gnl_clean is finished"

clean_all: mlx_clean libkd_clean gnl_clean clean

fclean:
	@$(RM) $(OBJS) $(OBJS_BON) $(NAME) .main .bonus
	@echo "fclean is finished"

libkd_fclean:
	@make fclean -C $(LIBKD_PATH) > /dev/null
	@echo "libkd_fclean is finished"

gnl_fclean:
	@make fclean -C $(GNL_PATH) > /dev/null
	@echo "gnl_fclean is finished"

fclean_all: mlx_clean libkd_fclean gnl_fclean fclean

re: fclean all

re_all: fclean_all all

norm:
	@make norm -C $(LIBKD_PATH)
	@norminette $(GNL_PATH) $(FOLDER)

leaks:
	leaks --atExit -- ./$(NAME)
	
##todo check licks

.PHONY: all bonus mlx libkd gnl clean \
mlx_clean libkd_clean gnl_clean clean_all \
fclean libkd_fclean gnl_fclean fclean_all \
re re_all norm leaks
