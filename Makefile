CC = cc
CFLAGS = -std=c90 -Wall -Wpedantic

# installation directory
INST_DIR = /bin

all: build install

build:
	mkdir -p bin
	$(CC) $(ARGS) -O3 -o bin/mkcmod mkcmod.c

build-dbg:
	mkdir -p bin
	$(CC) $(ARGS) -g -o bin/mkcmod_dbg mkcmod.c

clean:
	rm -r bin

install:
	su -c "mv bin/mkcmod $(INST_DIR)"

uninstall:
	su -c "rm $(INST_DIR)/mkcmod"
