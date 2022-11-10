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
    void embaralhar(Baralho _baralho);
}
#endif
