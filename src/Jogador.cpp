#ifndef JOGADOR_CPP
#define JOGADOR_CPP

#include "Jogador.hpp"
#include "Mao.hpp"

Jogador::Jogador(std::string nome){
    setEsta_jogando(true);
    setNome(nome);
    setFichas(100);
    Mao _mao;
    setNum_vitoria(0);
    setTipo("Nenhum");
}
        
Jogador::~Jogador(){_mao.~Mao();}
        
int Jogador::passar_vez(int jogador_atual){return jogador_atual + 1;}

int Jogador::desistir(int jogador_atual){
    setEsta_jogando(false);
    return jogador_atual + 1;
}

void Jogador::limpar(){}

//Erro: o identificador não esta definido (setFichas() e getFichas())
int aposta(std::string tipo_aposta, int valor_aposta){
    //Aposta normal
    if(tipo_aposta == "Aposta"){
        setFichas(getFichas() - valor_aposta);
        return valor_aposta;
    }
    //Aumenta a aposta
    else if(tipo_aposta == "Aumentar"){
        setFichas(getFichas() - valor_aposta);
        return valor_aposta;
    }
    //Aposta mesma quantidade que o ultimo jogador
    else if(tipo_aposta == "Call"){
        setFichas(getFichas() - valor_aposta);
        return valor_aposta;
    }
    //All-in(Aposta tudo)
    else if(tipo_aposta == "Apostar tudo"){
        valor_aposta = getFichas();
        setFichas(0);
        return valor_aposta;
    }
}

//GETTERS E SETTERS ---------------------------------------

bool Jogador::getEsta_jogando(){return _esta_jogando;} 
void Jogador::setEsta_jogando(bool esta_jogando){_esta_jogando = esta_jogando;} 
        
std::string Jogador::getNome(){return _nome;}
void Jogador::setNome(std::string nome){_nome = nome;} 

int Jogador::getFichas(){return _fichas;} 
void Jogador::setFichas(int fichas){_fichas = fichas;} 

Mao Jogador::getMao(){return _mao;}

int Jogador::getNum_vitoria(){return _num_vitoria;} 
void Jogador::setNum_vitoria(int num_vitoria){_num_vitoria = num_vitoria;} 

std::string Jogador::getTipo(){return _tipo;} 
void Jogador::setTipo(std::string tipo){_tipo = tipo;}

#endif
