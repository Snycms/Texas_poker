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
    
    //retorna objetos Carta
    Carta carta_topo();
  
    Carta flop(Baralho _baralho);
    Carta turn(Baralho _baralho);
    Carta river(Baralho _baralho);
  
    //Getter
    Carta getCarta();
}
#endif
