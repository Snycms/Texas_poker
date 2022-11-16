#ifndef CARTA_CPP
#define CARTA_CPP

#include "Carta.hpp"
#include "Mao.hpp"

Carta::Carta(int valor, std::string nome_naipe, bool rosto_baixo){
    setValor(valor);
    setNome_naipe(nome_naipe);
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

std::string Carta::getNome_naipe(){return _nome_naipe;}
void Carta::setNome_naipe(std::string nome_naipe){_nome_naipe = nome_naipe;}

bool Carta::getRosto_baixo(){return _rosto_baixo;}
void Carta::setRosto_baixo(bool rosto_baixo){_rosto_baixo = rosto_baixo;}

#endif