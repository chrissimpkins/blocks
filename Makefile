COMPILER = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++ -Wall -g
OPTIMIZATION = -O3
OBJECTS = main.o opts.o io.o 

INSTALL_PATH?=/usr/local

all: blocks

main.o: main.cpp opts.cpp io.cpp
	${COMPILER} ${CXXFLAGS} ${OPTIMIZATION} -c main.cpp

io.o: io.cpp
	${COMPILER} ${CXXFLAGS} ${OPTIMIZATION} -c io.cpp

opts.o: opts.cpp
	${COMPILER} ${CXXFLAGS} ${OPTIMIZATION} -c opts.cpp



blocks: ${OBJECTS}
	${COMPILER} ${CXXFLAGS} ${OPTIMIZATION} ${OBJECTS} -o blocks

install: blocks
	cp -f blocks ${INSTALL_PATH}/bin/blocks