#ifndef MAO_HPP
#define MAO_HPP

#include "Carta.hpp"

#include <vector>

class Mao{
  private:
    std::vector<Carta> _mao;
  
  public:
    //Inicia mao dos jogadores
    Mao();
    //Destrutor
    ~Mao();

    //Adiciona mais cartas no flop, turn e river = setMao
    void adiciona_carta(Carta carta); 

    //Compara as cartas da mao de um jogador e retorna a maior
    Carta maior_carta(); 

    //Retorna valor da mao do jogador
    int valor_mao(); 

};

#endif