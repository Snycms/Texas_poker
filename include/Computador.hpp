#ifndef COMPUTADOR_HPP
#define COMPUTADOR_HPP

#include "Jogador.hpp"

class Computador: public Jogador{
    private:
        int _dificuldade;
    
    public: 
        void fazer_jogada();

        int getDificuldade();
}

#endif