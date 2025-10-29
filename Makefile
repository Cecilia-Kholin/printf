# =======================
#     ft_printf Makefile
# =======================

# ---- Config ----
NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar
ARFLAGS     := rcs
RM          := rm -f

# ---- Rutas ----
SRC_DIR     := src
INC_DIR     := include

# Ruta relativa a tu libft (ajústala si está en otro sitio)
LIBFT_DIR   := ../libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

# Si libft tiene su propio include, añádelo también
INCLUDES    := -I$(INC_DIR) -I$(LIBFT_DIR)/include

# ---- Archivos ----
SRCS        := \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/ft_utils.c
OBJS        := $(SRCS:.c=.o)
DEPS        := $(SRCS:.c=.d)

# ---- Reglas ----
.PHONY: all clean fclean re libft

all: $(NAME)

# compila libft si no existe
libft:
	@$(MAKE) -C $(LIBFT_DIR)

# crea libftprintf.a combinando libft.a + tus objetos
$(NAME): libft $(OBJS)
	@echo "→ Creando $(NAME)"
	cp $(LIBFT_A) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# compilación individual con dependencias automáticas
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS)
