#include "Poker_Game.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

//No poker com 2 jogadores o Dealer também é o Small Blind

void main (){
    std::string opcao_jogo;
    std::cout << "tela inicial" << std::endl;
    std::cin >> opcao_jogo;

    if(opcao_jogo == "Novo Jogo"){
        int vencedor = 0;

        Poker_Game poker;
        Baralho baralho = poker.getBaralho();
        Jogador jogador = poker.getJogador();
        Computador bot = poker.getBot();

        std::string nome;
        std::cout << "Tela Digite o nome" << std::endl;
        std::cin >> nome;
        jogador.setNome(nome);

        int dificuldade;
        std::cout << "Tela slecione a dificuldade de jogo" << std::endl;
        std::cin >> dificuldade;
        bot.setDificuldade(dificuldade);

        //Depois que o jogador escolher a dificuldade jogo comeca
        int proxima_rodada = 0;

        do{
            poker.setRodada(proxima_rodada);
            
            baralho.embaralha();
            
            //Primeira rodada dealer é sorteado
            if(poker.getRodada() == 0){
                unsigned int semente = time(0);
                srand(semente);
                int dealer = (rand() % 2) + 1; //Numero aleatorio (1 ou 2)
                
                //Dealer é o jogador e o bot é Small Blind
                if(dealer == 1){jogador.setTipo("Dealer"); bot.setTipo("Big Blind");}
                 //Dealer é o bot e o jogador é o Small Blind
                else{jogador.setTipo("Big Blind"); bot.setTipo("Dealer");}
            }
            else{
                if(jogador.getTipo() == "Dealer"){jogador.setTipo("Big Blind"); bot.setTipo("Dealer");}
                else{jogador.setTipo("Dealer"); bot.setTipo("Big Blind");}
            }

            //Distribuindo as cartas - Big Blind depois Dealer
            if(jogador.getTipo() == "Big Blind"){
                for(int i=0; i<2; ++i){
                    //Uma carta para o Big Blind - Tira do baralho
                    baralho.distribui_carta("DAR CARTAS", jogador.getObjeto_mao_jogador());
                    baralho.remove_carta("DAR CARTAS");
                    //Uma carta para o Dealer - Tira do baralho
                    baralho.distribui_carta("DAR CARTAS", bot.getObjeto_mao_jogador());
                    baralho.remove_carta("DAR CARTAS");
                }
            }else{
                for(int i=0; i<2; ++i){
                    //Uma carta para o Big Blind - Tira do baralho
                    baralho.distribui_carta("DAR CARTAS", bot.getObjeto_mao_jogador());
                    baralho.remove_carta("DAR CARTAS");
                    //Uma carta para o Dealer - Tira do baralho
                    baralho.distribui_carta("DAR CARTAS", jogador.getObjeto_mao_jogador());
                    baralho.remove_carta("DAR CARTAS");
                }
            }
            
            //Pré-Flop
            

           


        }while(vencedor == 0);
        
    }

    else if(opcao_jogo == "Sair"){//Fecha o jogo
    }
}
