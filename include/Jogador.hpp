#ifndef JOGADORES_HPP
#define JOGADORES_HPP

#include "Mao.hpp"

#include <string>

class Jogador{
    private:
        std::string _nome;
        int _num_vitoria;
        int _fichas;
        Mao _mao;
        bool esta_jogando;
        std::string _tipo; //Pode ser Dealer, Small Blind ou Big Blind
    
    public:
        int aposta(int valor);
        int passar_vez();
    
        
        std::string getNome(); //Get nome do Jogador
        void setNome(std::string nome); //Set nome do Jogador

        int getNum_vitoria(); //Get numero de vitorias do Jogador
        void SetNum_vitoria(int num_vitoria); //Set numero de vitorias do Jogador

        int getFichas(); //Get numero de fichas do Jogador
        void setFichas(int fichas); //Set numero de fichas do Jogador

        bool getEsta_jogando(); //Get situação do Jogador
        void setEsta_jogando(bool esta_jogando); //Set situação do Jogador
};

#endif