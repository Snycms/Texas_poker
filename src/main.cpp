#include "Poker_Game.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


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
            //Criando um vector com os jogadores para alternar entre eles
            //std::vector<Jogador> participantes = {jogador, bot};
            
            baralho.embaralha();
            
            //Primeira rodada dealer é sorteado
            if(poker.getRodada() == 0){
                unsigned int semente = time(0);
                srand(semente);
                int dealer = (rand() % 2) + 1; //Numero aleatorio (1 ou 2)
                
                //Dealer é o jogador e o bot é Small Blind
                if(dealer == 1){jogador.setTipo("Dealer"); bot.setTipo("Small Blind");}
                 //Dealer é o bot e o jogador é o Small Blind
                else{jogador.setTipo("Small Blind"); bot.setTipo("Dealer");}
            }
            else{
                if(jogador.getTipo() == "Dealer"){jogador.setTipo("Small Blind"); bot.setTipo("Dealer");}
                else{jogador.setTipo("Dealer"); bot.setTipo("Small Blind");}
            }

            
            

           


        }while(vencedor == 0);
        
    }

    else if(opcao_jogo == "Sair"){//Fecha o jogo
    }
}
