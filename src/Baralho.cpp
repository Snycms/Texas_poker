#ifndef BARALHO_CPP
#define BARALHO_CPP

#include "Baralho.hpp"
#include "Mao.hpp"

#include <vector>

Baralho::Baralho(){
    std::string naipe[4] = {"paus","copas","espadas","ouros"};
    std::string nome[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

    for(int i=0; i<4; ++i){
        for(int j=1; j<14; ++j){
            _baralho.push_back(Carta(j, nome[j-1], naipe[i], true));
        }
    }
}

Baralho::~Baralho(){
}

void Baralho::embaralhar(Baralho &_baralho){}
    
Carta Baralho::carta_topo(){
    return
}

void Baralho::flop(Baralho &_baralho){

} 
void Baralho::turn(Baralho &_baralho){}
void Baralho::river(Baralho &_baralho){} 
  
Carta Baralho::getCarta(){}

#endif