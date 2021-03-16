# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 21:07:58 by jaeskim           #+#    #+#              #
#    Updated: 2021/03/16 18:56:11 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_test

CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS = -g -fsanitize=address

RM = rm
RMFLAGS = -rf

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRC_BONUS_DIR = src_bonus

LIBASM = ../libasm.a

SRCS = $(wildcard $(SRC_DIR)/*.c)
BONUS_SRCS = $(wildcard $(SRC_BONUS_DIR)/*.c)

vpath %.c $(SRC_DIR)

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
	@$(RM) $(RMFLAGS) $(NAME) $(NAME).dSYM
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'\n"

re : clean all

$(NAME) : $(LIBASM) $(SRCS)
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$(NAME)'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$(NAME)$(FG_TEXT)!\n"
	@$(CC) $(CFLAGS) $(LIBASM) -I $(INC_DIR) -o $(NAME) $(SRCS)
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

bonus : $(LIBASM) $(BONUS_SRCS)
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$(NAME)'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$(NAME)$(FG_TEXT)!\n"
	@$(CC) $(CFLAGS) $(LIBASM) -I $(INC_DIR) -o $(NAME) $(BONUS_SRCS)
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

.PHONY: all clean re bonus
