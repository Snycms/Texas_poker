#ifndef BARALHO_CPP
#define BARALHO_CPP

#include "Baralho.hpp"

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

Baralho &Baralho::resetar_baralho(){
    _baralho.clear();
    Baralho()
    return _baralho;
}

void Baralho::embaralhar_cartas(){
    unsigned int semente = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(_baralho.begin(), _baralho.end(), std::default_random_engine(semente));
    //_baralho.erase(_baralho.begin(), _baralho.end());
}
    
Carta Baralho::pegar_carta_topo(int posicao){return _baralho.at((_baralho.size()-1) - posicao);}

void Baralho::remover_carta(std::string jogada){
    if(jogada == "FLOP"){
        _baralho.erase(_baralho.end()-3, _baralho.end());
    }
    
    else if(jogada == "DAR CARTAS" || jogada == "TURN" || jogada == "RIVER"){
        _baralho.erase(_baralho.end());
    }
    
}

void Baralho::distribuir_cartas(std::string jogada, Mao &mao){
    if(jogada == "FLOP"){
        for(int j=0; j<3; ++j){
            mao.adiciona_carta(pegar_carta_topo(j));
            pegar_carta_topo(j).setRosto_baixo(false);
        }
    }
    else if(jogada == "DAR CARTAS" || jogada == "TURN" || jogada == "RIVER"){
        mao.adiciona_carta(pegar_carta_topo(0));
        pegar_carta_topo(0).setRosto_baixo(false);
    }
}

//TESTE ONLINE GDB
void Baralho::imprimir_baralho(){
    for(std::vector<Carta>::iterator it = _baralho.begin(); it != _baralho.end(); ++it){
        it->exibe_carta();
    }
    std::cout << _baralho.size() << std::endl;
}

#endif