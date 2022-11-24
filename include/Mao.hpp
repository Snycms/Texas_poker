#ifndef MAO_HPP
#define MAO_HPP

#include "Carta.hpp"

#include <vector>
#include <string>

class Mao{
  private:
    std::vector<Carta> _mao;
  
  public:
    //Inicia mao dos jogadores
    Mao();
    //Destrutor
    ~Mao();

    //Adiciona mais cartas no flop, turn e river = setMao
    void adiciona_carta(Carta carta); 

    //Compara as cartas da mao de um jogador e retorna a maior
    Carta maior_carta(); 

    //Retorna valor da mao do jogador
    std::string valor_mao(); 
    
    //POSSIVEIS MAOS--------------------------------------------

    //Straight Flush (Royal Flush, maior mão e um tipo de Straight Flush)
    int straight_flush();
    //Quadra 
    int quadra();
    //Full House
    int full_house();
    //Flush
    int flush();
    //Straight
    int straight();
    //Trinca 
    int trinca();
    //Dois Pares
    int dois_pares();
    //Par
    int par();
    //Carta Alta
    int carta_alta();

    //----------------------------------------------------------

    //TESTE ONLINE GDB
    void exibe_mao();
    
    //GETTERS E AUXILIARES---------------------------------------
    
    //Ordena as cartas da mao(maior para a menor)
    static bool ordena_mao_valor(Carta x, Carta y);

    //Get mao
    std::vector<Carta> &getMao();

};

#endif