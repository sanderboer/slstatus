# slstatus version
VERSION = 0

# customize below to fit your system

# paths
PREFIX = $(HOME)/.local
MANPREFIX = $(PREFIX)/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# flags
CPPFLAGS = -I$(X11INC) -I/usr/local/include -D_DEFAULT_SOURCE
CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os
LDFLAGS  = -L$(X11LIB) -L/usr/local/lib -s
LDLIBS   = -lX11 -lm -lkvm

# compiler and linker
CC = cc
