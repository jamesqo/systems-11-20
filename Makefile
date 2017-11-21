CFLAGS:=-Wall -Werror
DEBUG:=false

# make DEBUG=true emits debug info
ifeq ($(DEBUG),true)
	CFLAGS:=$(CFLAGS) -g
endif

.PHONY: all

all: main

main.o: main.c child.h parent.h
	gcc $(CFLAGS) -c $<

child.o: child.c child.h
	gcc $(CFLAGS) -c $<

parent.o: parent.c parent.h
	gcc $(CFLAGS) -c $<

main: main.o child.o parent.o
	gcc -o $@ $^

clean:
	rm -f *~ *.exe .*.swp *.o main

run: all
	./main
