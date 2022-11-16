#ifndef CARTAS_HPP
#define CARTAS_HPP

#include "Mao.hpp"

#include <string>

class Carta{
    private:
        int _valor;
        std::string _nome_naipe;
        bool _rosto_baixo;

    public:
        //Inicia as cartas
        Carta(int valor, std::string nome_naipe, bool rosto_baixo);
        ~Carta();

        //Vira a carta - Semelhante ao setRosto_baixo
        void virar();

        //GETTERS E SETTERS ---------------------------------------

        //Get valor da Carta
        int getValor(); 
        //Set valor da Carta
        void setValor(int valor);

        //Get nome e naipe da Carta
        std::string getNome_naipe();
        //Set nome e naipe da Carta
        void setNome_naipe(std::string nome_naipe);

        //Get se a Carta esta virada
        bool getRosto_baixo(); 
        //Set se a Carta esta virada
        void setRosto_baixo(bool rosto_baixo);
};

#endif