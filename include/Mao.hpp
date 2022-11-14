#ifndef MAO_HPP
#define MAO_HPP

#include <vector>

class Mao{
  private:
    std::vector<Carta> _mao;
  
  public:
    int comparar_mao(std::vector<Carta> pri_mao, std::vector<Carta> seg_mao); //Compara mao dos jogadores e retorna mais forte

    void adiciona_carta(Carta _carta); //Adiciona mais cartas no flop, turn e river
}

#endif