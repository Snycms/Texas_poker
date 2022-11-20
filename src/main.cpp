#include "Carta.hpp"
#include "Baralho.hpp"
#include "Mao.hpp"
#include "Jogador.hpp"


int main (){
    Baralho baralho;

    baralho.embaralha();
    
    Jogador jogador("Ernani");
    
    for(int i=0; i<7; ++i){
        baralho.distribui_carta("RIVER", jogador.getMao_jogador());
    }
    
    
    jogador.getMao_jogador().exibe_mao();
    //jogador.desistir(2);
    //std::cout << "Jogador: "<< jogador.getNome() << "\nFichas: " << jogador.getFichas() << "\nNumero vitoras: " << jogador.getNum_vitoria() << "\nEsta jogando:" << jogador.getEsta_jogando() << std::endl;
    
    
    //mao.valor_mao();
    
    //std::cout << "Valor: " << carta_topo.getValor() << " Nome: " << carta_topo.getNome() << " Naipe: " << carta_topo.getNaipe();
//#include "Computador.hpp" 
#include "Poker_Game.hpp"

#include <iostream>
#include <string>
#include <vector>

int main(){
    Baralho baralho;
    baralho.imprime_baralho();

    /*//FLOP
    for(int i=0; i<4; ++i){
        baralho.distribui_carta("FLOP", mao[i]);
    }
    baralho.remove_carta("FLOP");
    //FIM DO FLOP
    
    //TURN
    for(int i=0; i<4; ++i){
        baralho.distribui_carta("TURN", mao[i]);
    }
    baralho.remove_carta("TURN");
    //FIM DO TURN
    
    //RIVER
    for(int i=0; i<4; ++i){
        baralho.distribui_carta("RIVER", mao[i]);
    }
    baralho.remove_carta("RIVER");
    //FIM DO RIVER*/
}
