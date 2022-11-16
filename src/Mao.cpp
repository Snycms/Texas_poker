#ifndef MAO_CPP
#define MAO_CPP

#include "Mao.hpp"
#include "Carta.hpp"
#include "Baralho.hpp"

Mao::Mao(){std::vector<Carta> _mao;}

Mao::~Mao(){_mao.clear();}

void Mao::adiciona_carta(Carta carta){_mao.push_back(carta);}

Carta Mao::maior_carta(){
    Carta maior = _mao.front();
    for(std::vector<Carta>::iterator it = _mao.begin(); it != _mao.end(); ++it){
        if(maior.getValor() <= it->getValor()){
            maior = *it;
        }
    }
    return maior;
}

int Mao::valor_mao(){

}

#endif