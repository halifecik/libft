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
INC_DIR		= includes
OBJ_DIR		= $(SRC_DIR)/obj
LIBC_DIR  	= $(SRC_DIR)/libc
ADD_DIR		= $(SRC_DIR)/additional
BONUS_DIR	= $(SRC_DIR)/bonus

# Source Files
LIBC_SRCS =		ft_atoi.c \
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

ADD_SRCS =		ft_itoa.c \
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

BONUS_SRCS =	ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c

# Sources & Objects
LIBC_SRC 	= $(addprefix src/libc/, $(LIBC_SRCS))
ADD_SRC  	= $(addprefix src/additional/, $(ADD_SRCS))
BON_SRC 	= $(addprefix src/bonus/, $(BONUS_SRCS))

SRCS = $(LIBC_SRC) $(ADD_SRC)
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BON_SRC:src/%.c=$(OBJ_DIR)/%.o)

# Output Binary
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS)
	@echo "$(CYAN)Linking all objects...$(RESET)"
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(BOLD)$(GREEN)Mandatory & Bonus build complete: $(NAME)$(RESET)"

man: $(OBJS)
	@echo "$(CYAN)Linking mandatory objects...$(RESET)"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(BOLD)$(GREEN)Mandatory build complete: $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing binary...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re man bonus