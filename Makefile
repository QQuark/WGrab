CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-lX11

all: WGrab

WGrab: WGrab.o dsimple.o clientwin.o
	gcc $? $(LDFLAGS) -o $@
	
clean:
	rm -f WGrab.o dsimple.o clientwin.o WGrab
