CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-L /usr/X11R6/lib -lX11 -lXtst -lXext

all: WGrab

WGrab: WGrab.o dsimple.o clientwin.o

clean:
	rm -f WGrab.o dsimple.o clientwin.o WGrab
