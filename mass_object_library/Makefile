# *******************************************************************
# Copyright (c) University of Luxembourg 2023.
# Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
# ********************************************************************

CC = gcc  # C compiler
CFLAGS = -fsanitize=address -fsanitize=undefined -Wall -Wextra -O2 -g -Iinclude  -fprofile-arcs -ftest-coverage -fPIC# C flags
LDFLAGS = -fsanitize=address -fsanitize=undefined -lgcov # linking flags
RM = rm -f   # rm command
TARGET_LIB = ./bin/libmasstesting.a  # target lib
AR = ar
MKDIR = mkdir -p

SRCS = src/circle.c \
    src/rectangle.c \
    src/square.c \
    src/triangle.c \
    src/error.c

OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(MKDIR) bin
	$(AR) rcs $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d) $(SRCS:.c=.gcno) $(SRCS:.c=.gcda) $(SRCS:.c=.gcov)
