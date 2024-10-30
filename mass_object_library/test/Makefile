# *******************************************************************
# Copyright (c) University of Luxembourg 2023.
# Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
# ********************************************************************

CC = gcc  # C compiler
CFLAGS = -fsanitize=address -fsanitize=undefined -Wall -Wextra -O2 -g  -I../include -I.
LDFLAGS =  -fsanitize=address -fsanitize=undefined -L../bin/ -lmasstesting -lgcov #linking flags
CFLAGS_FLAKY = -DFLAKY
RM = rm -f   # rm command
NAME = run_test  # target lib
SRCS = main.c tests.c

all:
	$(CC) $(CFLAGS) $(SRCS) $(LDFLAGS) -o $(NAME)

flaky:
	$(CC) $(CFLAGS) $(CFLAGS_FLAKY) $(SRCS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(NAME)
