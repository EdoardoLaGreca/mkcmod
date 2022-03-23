CC = cc

# installation directory
INST_DIR = /bin

all: build install

build:
	mkdir -p bin
	$(CC) -o bin/mkcmod mkcmod.c

build-dbg:
	mkdir -p bin
	$(CC) -g -o bin/mkcmod_dbg mkcmod.c

clean:
	rm -r bin

install:
	mv mkcmod $(INST_DIR)

uninstall:
	rm $(INST_DIR)/mkcmod
	
