CC := g++
CFLAGS := -std=c++11 -Wall
TARGET := program

BUILD_DIR := ./build
SRC_DIR := ./src
INCLUDE_DIR := ./include

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Baralho.o ${BUILD_DIR}/Carta.o ${BUILD_DIR}/Computador.o ${BUILD_DIR}/Jogador.o ${BUILD_DIR}/Mao.o ${BUILD_DIR}/Poker_Game.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

#---------

${BUILD_DIR}/Carta.o: ${INCLUDE_DIR}/Carta.hpp ${SRC_DIR}/Carta.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Carta.cpp -o ${BUILD_DIR}/Carta.o

${BUILD_DIR}/Mao.o: ${INCLUDE_DIR}/Mao.hpp ${SRC_DIR}/Mao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Mao.cpp -o ${BUILD_DIR}/Mao.o

${BUILD_DIR}/Baralho.o: ${INCLUDE_DIR}/Baralho.hpp ${SRC_DIR}/Baralho.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Baralho.cpp -o ${BUILD_DIR}/Baralho.o

${BUILD_DIR}/Computador.o: ${INCLUDE_DIR}/Computador.hpp ${SRC_DIR}/Computador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Computador.cpp -o ${BUILD_DIR}/Computador.o

${BUILD_DIR}/Jogador.o: ${INCLUDE_DIR}/Jogador.hpp ${SRC_DIR}/Jogador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Jogador.cpp -o ${BUILD_DIR}/Jogador.o

${BUILD_DIR}/Poker_Game.o: ${INCLUDE_DIR}/Poker_Game.hpp ${SRC_DIR}/Poker_Game.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Poker_Game.cpp -o ${BUILD_DIR}/Poker_Game.o

#---------

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Baralho.hpp ${INCLUDE_DIR}/Carta.hpp ${INCLUDE_DIR}/Computador.hpp ${INCLUDE_DIR}/Jogador.hpp ${INCLUDE_DIR}/Mao.hpp ${INCLUDE_DIR}/Poker_Game.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/* 