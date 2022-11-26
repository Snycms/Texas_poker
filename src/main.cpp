#include "Poker_Game.hpp"

#include <iostream>
#include <string>
#include <vector>


int main (){

    std::string opcao_jogo;

    std::cout << "tela inicial" << std::endl;
    std::cin >> opcao_jogo;

    if(opcao_jogo == "Novo Jogo"){
        Poker_Game poker;
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

        poker.jogar_rodada();
    }
}
