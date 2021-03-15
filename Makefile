# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 21:07:58 by jaeskim           #+#    #+#              #
#    Updated: 2021/03/16 02:02:44 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

ASMC = nasm
ASMFLAGS = -fmacho64 -g

AR = ar
ARFLAGS = crs

CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS = -g -fsanitize=address
ifeq ($(DEBUG),true)
	CDEBUG = -g
endif

RM = rm
RMFLAGS = -f

SRC_DIR = src
OBJ_DIR = obj

SRC_BONUS_DIR = src_bonus

SRCS = $(wildcard $(SRC_DIR)/*.s)
BONUS_SRCS = $(wildcard $(SRC_BONUS_DIR)/*.s)

vpath %.s $(SRC_DIR) $(SRC_BONUS_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.s=.o)))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRCS:.s=.o)))

# Color
CL_BOLD	 = \e[1m
CL_DIM	= \e[2m
CL_UDLINE = \e[4m

NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

FG_WHITE = $(NO_COLOR)\e[0;37m
FG_TEXT = $(NO_COLOR)\e[38;2;189;147;249m
FG_TEXT_PRIMARY = $(NO_COLOR)$(CL_BOLD)\e[38;2;255;121;198m

LF = \e[1K\r$(NO_COLOR)
CRLF= \n$(LF)

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'s Object files...\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)\n"

re : fclean all

re_bonus : fclean bonus

lib_clean : $(LIBFT)_fclean $(MLX)_clean

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.s | $(OBJ_DIR)
	@$(ASMC) $(ASMFLAGS) $< -o $@
	@printf "$(LF)🚧 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"

$(NAME) : $(OBJS)
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$(NAME)'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$(NAME)$(FG_TEXT)!\n"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

bonus : $(OBJS) $(OBJS_BONUS)
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$(NAME)'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$(NAME)_bonus!$(FG_TEXT)!\n"
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

TEST_DIR = test
TEST = $(TEST_DIR)/ft_test

test : test_build
	@$(TEST)

test_build : $(NAME) $(TEST_FILE)
	@make -C $(TEST_DIR) re

bonus_test : bonus_test_build
	@$(TEST)

bonus_test_build : bonus $(TEST_FILE)
	@make -C $(TEST_DIR) clean bonus

.PHONY: all clean fclean re \
	test test_build \
	bonus bonus_test bonus_test_build
