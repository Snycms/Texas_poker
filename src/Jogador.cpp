#ifndef JOGADOR_CPP
#define JOGADOR_CPP

#include "Jogador.hpp"

#include <iostream>

Jogador::Jogador(){
    setEsta_jogando(true);
    setNome("");
    setFichas(100);
    Mao _mao;
    setNum_vitoria(0);
    setTipo("");
}
        
Jogador::~Jogador(){_mao.~Mao();}

void Jogador::virar_cartas(){
    std::vector<Carta> mao = getVector_mao_jogador();
    mao.at(0).setRosto_baixo(false);
    mao.at(1).setRosto_baixo(false);
}

void Jogador::adicionar_fichas(int pot){
    setFichas(getFichas() + pot);
}

//Acoes que os jogadores podem realizar-----------------------------
        
void Jogador::dar_check_ou_fold(std::string acao){
    if(acao == "FOLD"){setEsta_jogando(false);}

    else if(acao == "CHECK"){
        //Não faz nada
    }
}

int Jogador::apostar_fichas(std::string tipo_aposta, int valor_aposta){
    if(tipo_aposta == "APOSTAR" || tipo_aposta == "AUMENTAR"){
        //Verifica se tem fichas sufucientes
        if(valor_aposta >= getFichas()){
            valor_aposta = getFichas();
            setApostou_tudo(true);
            setFichas(0);
            return valor_aposta;
        }
        else{
            setFichas(getFichas() - valor_aposta);
            return valor_aposta;
        }
    }
    else if(tipo_aposta == "CALL"){
        //verifica se tem fichas sufucientes
        if(valor_aposta >= getFichas()){
            valor_aposta = getFichas();
            setFichas(0);
            setApostou_tudo(true);
            return valor_aposta;
        }
        else{
            setFichas(getFichas() - valor_aposta);
            return valor_aposta;
        }
    }
    //All-in(Aposta tudo)
    else{
        valor_aposta = getFichas();
        setFichas(0);
        setApostou_tudo(true);
        return valor_aposta;
    }
}
//-------------------------------------------------------------------

void Jogador::limpar_mesa(){}

//TESTE GDB ONLINE

void Jogador::imprimir_jogador(){
    std::cout << "Esta jogando: " << getEsta_jogando() << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Fichas: "<< getFichas() << std::endl;
    std::cout << "Sua mao: " << std::endl;
    _mao.imprimir_mao();
    std::cout << "Vitorias: " << getNum_vitoria() << std::endl;
    std::cout << "Tipo: " << getTipo();
    std::cout << std::endl;
}

//GETTERS E SETTERS ---------------------------------------

bool Jogador::getEsta_jogando(){return _esta_jogando;} 
void Jogador::setEsta_jogando(bool esta_jogando){_esta_jogando = esta_jogando;} 
        
std::string Jogador::getNome(){return _nome;}
void Jogador::setNome(std::string nome){_nome = nome;} 

int Jogador::getFichas(){return _fichas;} 
void Jogador::setFichas(int fichas){_fichas = fichas;} 

Mao &Jogador::getObjeto_mao_jogador(){return _mao;}

std::vector<Carta> &Jogador::getVector_mao_jogador(){return _mao.getMao();}

int Jogador::getNum_vitoria(){return _num_vitoria;} 
void Jogador::setNum_vitoria(int num_vitoria){_num_vitoria = num_vitoria;} 

std::string Jogador::getTipo(){return _tipo;} 
void Jogador::setTipo(std::string tipo){_tipo = tipo;}

bool Jogador::getApostou_tudo(){return _apostou_tudo;}
void Jogador::setApostou_tudo(bool apostou_tudo){_apostou_tudo = apostou_tudo;}

#endif
