# Font Settings
RESET   = \033[0m
BOLD    = \033[1m
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m

# Compiler & Flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iincludes

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
LIBC_DIR  	= $(SRC_DIR)/libc
ADD_DIR		= $(SRC_DIR)/additional
BONUS_DIR	= $(SRC_DIR)/bonus

# Source Files
LIBC_SRC =	ft_atoi.c \
    		ft_isdigit.c \
    		ft_memset.c \
    		ft_strncmp.c \
    		ft_bzero.c \
    		ft_isprint.c \
    		ft_strchr.c \
    		ft_strnstr.c \
    		ft_calloc.c \
    		ft_memchr.c \
    		ft_strdup.c \
    		ft_strrchr.c \
    		ft_isalnum.c \
    		ft_memcmp.c \
    		ft_strlcat.c \
    		ft_tolower.c \
    		ft_isalpha.c \
    		ft_memcpy.c \
    		ft_strlcpy.c \
    		ft_toupper.c \
    		ft_isascii.c \
    		ft_memmove.c \
    		ft_strlen.c

ADD_SRC =	ft_itoa.c \
    		ft_putchar_fd.c \
    		ft_putendl_fd.c \
    		ft_putnbr_fd.c \
    		ft_putstr_fd.c \
    		ft_split.c \
    		ft_striteri.c \
    		ft_strjoin.c \
    		ft_strmapi.c \
    		ft_strtrim.c \
    		ft_substr.c

# Sources & Objects
LIBC_SRC = $(addprefix src/libc/, $(LIBC_SRC))
ADD_SRC  = $(addprefix src/additional/, $(ADD_SRC))

SRCS = $(LIBC_SRC) $(ADD_SRC)
OBJS = $(SRCS:.c=.o)

# Output Binary
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
    @echo "$(CYAN)Linking objects...$(RESET)"
    @ar rcs $(NAME) $(OBJS)
    @echo "$(BOLD)$(GREEN)Build complete: $(NAME)$(RESET)"

obj/%.o: src/libc/%.c
    @mkdir -p obj
    @echo "$(YELLOW)Compiling $<...$(RESET)"
    @$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/additional/%.c
    @mkdir -p obj
    @echo "$(YELLOW)Compiling $<...$(RESET)"
    @$(CC) $(CFLAGS) -c $< -o $@

clean:
    @echo "$(RED)Cleaning object files...$(RESET)"
    @rm -rf $(OBJ_DIR)

fclean: clean
    @echo "$(RED)Removing binary...$(RESET)"
    @rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re