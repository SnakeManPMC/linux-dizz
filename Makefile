#

CC	= gcc
LIBDIR  = 
MAINDIR = 

# Without shadow support

CFLAGS  =

LIBS	= 

all:		dizz cln test dir2mysql

dizz:           dizz.c
	        $(CC) -o $@ $<

cln:            cln.c
	        $(CC) -o $@ $<

test:           test.c
	        $(CC) -o $@ $<

dir2mysql:      dir2mysql.c
	        $(CC) -o $@ $<
