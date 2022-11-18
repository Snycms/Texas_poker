#include <iostream>
#include <vector>
#include <string>

#include "Carta.hpp"
#include "Mao.hpp"
#include "Baralho.hpp"
#include "Jogador.hpp"


int main (){
    Baralho baralho;

    baralho.embaralha();
    
    Jogador jogador("Ernani");
    
    Mao mao = jogador.getMao_jogador();
    
    for(int i=0; i<7; ++i){
        baralho.distribui_carta("RIVER", jogador.getMao_jogador());
    }
    
    
    jogador.getMao_jogador().exibe_mao();
    //jogador.desistir(2);
    //std::cout << "Jogador: "<< jogador.getNome() << "\nFichas: " << jogador.getFichas() << "\nNumero vitoras: " << jogador.getNum_vitoria() << "\nEsta jogando:" << jogador.getEsta_jogando() << std::endl;
    
    
    //mao.valor_mao();
    
    //std::cout << "Valor: " << carta_topo.getValor() << " Nome: " << carta_topo.getNome() << " Naipe: " << carta_topo.getNaipe();
    
    return 0;
}
