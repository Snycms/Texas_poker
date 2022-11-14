#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "Carta.hpp"
#include "Jogador.hpp"

#include <string>
#include <vector>

class Baralho{
  private:
    std::vector<Carta> _baralho;
  
  public:
    Baralho();
    ~Baralho();
    void embaralhar(Baralho &_baralho);
    
    //Retorna primeira carta de cima do baralho 
    Carta carta_topo();

    //Adiciona 3 cartas à mesa e à mao dos jogadores 
    void flop(Baralho &_baralho); 
    //Adiciona 1 carta à mesa e à mao dos jogadores
    void turn(Baralho &_baralho); 
    //Adiciona 1 carta à mesa e à mao dos jogadores
    void river(Baralho &_baralho); 
  
    //Get Carta
    Carta getCarta(); 
}

#endif