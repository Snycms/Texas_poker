#ifndef COMPUTADOR_HPP
#define COMPUTADOR_HPP

#include "Jogador.hpp"

class Computador: public Jogador{
    private:
        int _dificuldade;
    
    public: 
        Computador();
        ~Computador(){};
        
        //Retorna numero de fichas que o bot vai apostar
        int fazer_jogada(int pot, int &qtd_raise_bet, int aposta_anterior, bool &aumentou_aposta);

        //GETTERS E SETTERS ---------------------------------------

        //Get dificuldade do computador
        int getDificuldade();
        //Set dificuldade do computador
        void setDificuldade(int dificuldade);
};

#endif