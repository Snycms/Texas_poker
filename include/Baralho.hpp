#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "Carta.hpp"
#include "Mao.hpp"

#include <string>
#include <vector>

class Baralho{
  private:
    std::vector<Carta> _baralho;
  
  public:
    Baralho();
    ~Baralho();

    Baralho resetar_baralho();
    
    void embaralhar_cartas();
    
    //Retorna primeira carta de cima do baralho 
    Carta pegar_carta_topo(int posicao);

    //Remove carta do topo
    void remover_carta(std::string jogada);

    //Da as primeiras 2 cartas, Flop(3 cartas), Turn(1 cartas) e o River(1 carta)
    void distribuir_cartas(std::string jogada, Mao &mao);

    //TESTE ONLINE GDB
    void imprimir_baralho();
};

#endif