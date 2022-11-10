#ifndef JOGADORES_HPP
#define JOGADORES_HPP

#include "Mao.hpp"

#include <string>



class Jogador{
    private:
        std::string _nome;
        int _num_vitoria;
        int _fichas;
        int _aposta;
        //Mao
        bool esta_jogando;
    
    public:
        int aposta(int valor);
        int passar_vez();
         


        //GETTERS E SETTERS

        std::string getNome();
        void setNome(std::string nome);

        int getNum_vitoria();
        void SetNum_vitoria(int num_vitoria);

        int getFichas();
        void setFichas(int fichas);

        bool getEsta_jogando();
        void setEsta_jogando(bool esta_jogando);
}

#endif