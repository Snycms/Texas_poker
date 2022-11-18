#ifndef JOGADORES_HPP
#define JOGADORES_HPP

#include "Mao.hpp"

#include <string>

class Jogador{
    private:
        bool _esta_jogando;
        std::string _nome;
        int _fichas;
        Mao _mao;
        int _num_vitoria;

        //Pode ser Dealer, Small Blind ou Big Blind
        std::string _tipo; 
    
    public:
        Jogador(std::string nome);
        ~Jogador();
        
        int passar_vez();
        int desistir();
        void limpar();

        //Opções de aposta

        int aposta(int valor_aposta);
        int aumentar(int valor_aposta);
        //Aposta mesmo valor do ultimo jogador
        int call();
        //Aposta tudo
        int All_in();
        
        //GETTERS E SETTERS ---------------------------------------
    
        //Get nome do Jogador
        std::string getNome();
        //Set nome do Jogador
        void setNome(std::string nome); 

        //Get numero de vitorias do Jogador
        int getNum_vitoria(); 
        //Set numero de vitorias do Jogador
        void setNum_vitoria(int num_vitoria); 

        //Get numero de fichas do Jogador
        int getFichas(); 
        //Set numero de fichas do Jogador
        void setFichas(int fichas); 

        //Get estado do Jogador
        bool getEsta_jogando(); 
        //Set estado do Jogador
        void setEsta_jogando(bool esta_jogando); 
};

#endif