#ifndef CARTA_CPP
#define CARTA_CPP

#include "Carta.hpp"

Carta::Carta(int valor, std::string nome, std::string naipe, bool rosto_baixo){
    setValor(valor);
    setNome(nome);
    setNaipe(naipe);
    setRosto_baixo(rosto_baixo);
}

Carta::~Carta(){}

void Carta::virar(){
    if(getRosto_baixo() == true){
        bool virar = false;
        setRosto_baixo(virar);
    }
}


//GETTERS E SETTERS ---------------------------------------

int Carta::getValor(){return _valor;}
void Carta::setValor(int valor){_valor = valor;}

std::string Carta::getNome(){return _nome;}
void Carta::setNome(std::string nome){_nome = nome;}

std::string Carta::getNaipe(){return _naipe;}
void Carta::setNaipe(std::string naipe){_naipe = naipe;}

bool Carta::getRosto_baixo(){return _rosto_baixo;}
void Carta::setRosto_baixo(bool rosto_baixo){_rosto_baixo = rosto_baixo;}

#endif