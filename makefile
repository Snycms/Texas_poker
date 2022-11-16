CC := g++
FLAGS := -I include/ -Wall
BUILD_DIR := build/
SRC_DIR := src/
TARGET := main.out

main.out: Carta.o Mao.o Baralho.o Jogador.o Computador.o Poker_Game.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) build/Carta.o

Carta.o: 
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c src/Carta.cpp -o build/Carta.o

Mao.o: 
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c src/Mao.cpp -o build/Mao.o

Baralho.o:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c src/Baralho.cpp -o build/Baralho.o

Jogador.o:	
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c src/Jogador.cpp -o build/Jogador.o

Computador: Jogador.o
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c src/Computador.cpp -o build/Jogador.o

Poker_Game.o: 
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c src/Poker_Game.cpp -o build/Poker_Game.o

clean:
	$(RM) -r $(BUILD_DIR)/* $(TARGET)