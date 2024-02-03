CC = gcc
ROWS ?=   #?= allows you to set thru command line
COLS ?= 
CFLAGS = $(if $(ROWS),-DROWS=$(ROWS) ,)$(if $(COLS),-DCOLS=$(COLS) ,)-std=c17 -Wall  -Werror -pedantic -g

Life: main.o life.o helpers.o
	$(CC) $(CFLAGS) -o $@ $^

# Runs clean but also removes any alternate executables (e.g. Life_6_6 for a 6x6 grid)
superclean: clean
	$(RM) Life_*

clean:
	$(RM) Life *.o

test-1: Life
	./Life 9 1110010100101001
