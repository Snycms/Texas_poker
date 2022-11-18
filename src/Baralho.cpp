#ifndef BARALHO_CPP
#define BARALHO_CPP

#include "Baralho.hpp"
#include "Carta.hpp"
#include "Mao.hpp"

#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

//TESTE ONLINE GDB
#include <iostream>

Baralho::Baralho(){
    std::string naipe[4] = {"paus", "copas", "espadas", "ouros"};
    std::string nome[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    for(int i=0; i<4; ++i){
        for(int j=0; j<13; ++j){
            _baralho.push_back(Carta((j+1), nome[j], naipe[i], true));
        }
    }
}

Baralho::~Baralho(){_baralho.clear();}

void Baralho::embaralha(){
    //unsigned int semente = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(_baralho.begin(), _baralho.end(), std::default_random_engine(1));
}
    
Carta Baralho::carta_topo(){return _baralho.back();}

void Baralho::remove_carta(){_baralho.erase(_baralho.end());}

void Baralho::distribui_carta(std::string jogada, Mao &mao){
    if(jogada == "DAR CARTAS"){
        for(int i=0; i<2; ++i){
            mao.adiciona_carta(carta_topo());
            remove_carta();
        }
    }
    else if(jogada == "FLOP"){
        for(int i=0; i<3; ++i){
            mao.adiciona_carta(carta_topo());
            remove_carta();
        }
    }
    else if(jogada == "TURN" or jogada == "RIVER"){
        mao.adiciona_carta(carta_topo());
        remove_carta();
    }
}

//TESTE ONLINE GDB
void Baralho::imprime_baralho(){
    for(std::vector<Carta>::iterator it = _baralho.begin(); it != _baralho.end(); ++it){
        it->exibe_carta();
    }
    std::cout << _baralho.size();
}

#endif