#ifndef CARTA_CPP
#define CARTA_CPP

#include "Carta.hpp"

//TESTE ONLINE GDB
#include <iostream>

Carta::Carta(int valor, std::string nome, std::string naipe, bool rosto_baixo){
    setValor(valor);
    _nome = nome;
    _naipe = naipe;
    setRosto_baixo(rosto_baixo);
}

Carta::~Carta(){}

void Carta::virar_carta(){
    if(getRosto_baixo() == true){
        bool virar = false;
        setRosto_baixo(virar);
    }
}

//TESTE ONLINE GDB
void Carta::imprimir_carta(){
    std::cout << "Valor: " << getValor() << " - ";
    std::cout << "Nome: " << getNome() << " - ";
    std::cout << "Naipe: " << getNaipe() << std::endl;
}

//GETTERS E SETTERS ---------------------------------------

int Carta::getValor(){return _valor;}
void Carta::setValor(int valor){_valor = valor;}

std::string Carta::getNome(){return _nome;}

std::string Carta::getNaipe(){return _naipe;}

bool Carta::getRosto_baixo(){return _rosto_baixo;}
void Carta::setRosto_baixo(bool rosto_baixo){_rosto_baixo = rosto_baixo;}

#endif