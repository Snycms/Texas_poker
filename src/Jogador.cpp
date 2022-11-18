#ifndef JOGADOR_CPP
#define JOGADOR_CPP

#include "Jogador.hpp"
#include "Carta.hpp"
#include "Mao.hpp"
#include "Baralho.hpp"

Jogador::Jogador(std::string nome){
    setEsta_jogando(true);
    setNome(nome);
    setFichas(100);
    Mao _mao;
    setNum_vitoria(0);
    
}
        
Jogador::~Jogador(){_mao.~Mao();}
        
int Jogador::passar_vez(){}

int Jogador::desistir(){

}

void Jogador::limpar(){}

int aposta(int valor_aposta);

int aumentar(int valor_aposta);
        
int call();
        
int All_in();

//GETTERS E SETTERS ---------------------------------------
        
std::string Jogador::getNome(){return _nome} 
void Jogador::setNome(std::string nome){_nome = nome;} 

int Jogador::getNum_vitoria(){return _num_vitoria} 
void Jogador::setNum_vitoria(int num_vitoria){_num_vitoria = num_vitoria;} 

int Jogador::getFichas(){return _fichas;} 
void Jogador::setFichas(int fichas){_fichas = fichas;} 

bool Jogador::getEsta_jogando(){return _esta_jogando;} 
void Jogador::setEsta_jogando(bool esta_jogando){_esta_jogando = esta_jogando;} 

#endif