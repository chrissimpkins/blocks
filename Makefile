COMPILER = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++ -Wall -g
OPTIMIZATION = -O3
OBJECTS = main.o filemaker.o io.o opts.o

INSTALL_PATH?=/usr/local

all: blocks

main.o: main.cpp main.h print.h
	${COMPILER} ${CXXFLAGS} ${OPTIMIZATION} -c main.cpp

filemaker.o: filemaker.cpp filemaker.h print.h
	${COMPILER} ${CXXFLAGS} ${OPTIMIZATION} -c filemaker.cpp

io.o: io.cpp io.h print.h
	${COMPILER} ${CXXFLAGS} ${OPTIMIZATION} -c io.cpp

opts.o: opts.cpp opts.h print.h
	${COMPILER} ${CXXFLAGS} ${OPTIMIZATION} -c opts.cpp

blocks: ${OBJECTS}
	${COMPILER} ${CXXFLAGS} ${OPTIMIZATION} ${OBJECTS} -o blocks

install: blocks
	cp -f blocks ${INSTALL_PATH}/bin/blocks