#ifndef MAO_CPP
#define MAO_CPP

#include "Mao.hpp"
#include "Carta.hpp"

//TESTE ONLINE GDB
#include <iostream>

Mao::Mao(){std::vector<Carta> _mao;}

Mao::~Mao(){_mao.clear();}

void Mao::adiciona_carta(Carta carta){_mao.push_back(carta);}

Carta &Mao::maior_carta(){
    Carta maior = _mao.front();
    for(std::vector<Carta>::iterator it = _mao.begin(); it != _mao.end(); ++it){
        if(maior.getValor() <= it->getValor()){
            maior = *it;
        }
    }
    return maior;
}

/*int Mao::valor_mao(){
//Royal Flush
    //Straight Flush
    //Quadra
    //Full House
    //Flush
    //Straight
    //Trinca
    //Dois Pares
    //Cartas recebidas pelo jogador
    Carta cartas_jogador[2] = {_mao.front(), _mao.at(1)};
    
    std::vector<Carta> mao_mesa = _mao;
    mao_mesa.erase(mao_mesa.begin(), mao_mesa.begin()+2);
    
    std::cout << "Cartas copia: \n";
    for(int i=0; i<7; ++i){
        mao_mesa.at(i).exibe_carta();
    }
}*/

//TESTE ONLINE GDB
void Mao::exibe_mao(){
    for(std::vector<Carta>::iterator it = _mao.begin(); it != _mao.end(); ++it){
        it->exibe_carta();
    }
}

std::vector<Carta> &Mao::getMao(){return _mao;}


#endif