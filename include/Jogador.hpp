#ifndef JOGADORES_HPP
#define JOGADORES_HPP

#include "Mao.hpp"

#include <string>

class Jogador{
    protected:
        bool _esta_jogando;
        std::string _nome;
        int _fichas;
        Mao _mao;
        int _num_vitoria;
        //Pode ser Dealer, Small Blind ou Big Blind
        std::string _tipo;
    
    public:
        Jogador();
        ~Jogador();
        
        void virar_cartas();

        void adicionar_fichas(int pot);
        
        //Acoes que os jogadores podem realizar----------------------

        //Passar a vez sem apostar(CHECK) ou desistir(FOLD)
        void dar_check_ou_fold(std::string acao);

        //Tipos de aposta:
        //Aposta normal - Aumentar aposta
        //Call(Aposta mesma quantidade que o ultimo jogador)
        //All-in(Aposta tudo)

        int apostar_fichas(std::string tipo_aposta, int valor_aposta);

        //------------------------------------------------------------

        //Adicionar vitoria numero para o Jogador
        void adicionar_vitoria(); 

        //TESTE GDB ONLINE
        void imprimir_jogador();
        
        //GETTERS E SETTERS ---------------------------------------
    
        //Get estado do Jogador
        bool getEsta_jogando(); 
        //Set estado do Jogador
        void setEsta_jogando(bool esta_jogando); 

        //Get nome do Jogador
        std::string getNome();
        //Set nome do Jogador
        void setNome(std::string nome); 

        //Get numero de fichas do Jogador
        int getFichas(); 
        //Set numero de fichas do Jogador
        void setFichas(int fichas); 

        //Get numero de vitorias do Jogador
        int getNum_vitoria(); 
        //Set numero de vitorias do Jogador
        void setNum_vitoria(int num_vitoria);

        //Get objeto mao do Jogador
        Mao &getObjeto_mao_jogador();
        //Get vector mao do Jogador
        std::vector<Carta> &getVector_mao_jogador();
    
        //Get tipo de Jogador(Dealer, Small Blind ou Big Blind)
        std::string getTipo();
        //Set tipo de Jogador(Dealer, Small Blind ou Big Blind)
        void setTipo(std::string tipo);
};

#endif