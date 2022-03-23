CC = cc
ARGS = -std=c90 -Wall -Wpedantic

# installation directory
INST_DIR = /bin

all: build install

build:
	mkdir -p bin
	$(CC) $(ARGS) -o bin/mkcmod mkcmod.c

build-dbg:
	mkdir -p bin
	$(CC) $(ARGS) -g -o bin/mkcmod_dbg mkcmod.c

clean:
	rm -r bin

install:
	mv mkcmod $(INST_DIR)

uninstall:
	rm $(INST_DIR)/mkcmod
	
