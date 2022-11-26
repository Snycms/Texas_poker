#ifndef COMPUTADOR_CPP
#define COMPUTADOR_CPP

#include "Computador.hpp"

Computador::Computador(int dificuldade){setDificuldade(dificuldade);}

Computador::~Computador(){}

void Computador::fazer_jogada(int pot, int qtd_raise, int raise, int jogadores_presentes, int jogador_atual, int ultima_aposta){
    if(getDificuldade() == 1){}

    //metodo de Jean Rachlin e Gary Higgins
    //metodo depende do total de apostas divido pelo ((quantidades de raise + 1) vezes o numero de jogadores que ainda vão jogar que será 1
    //vezes o numero de jogadores que é 2 vezes a (aposta necessaria para continuar no jogo + 1))
    else if(getDificuldade() == 2){
        int jogada;
        float t = 1;
        float v = pot / ((pot+1) * 1 * 2 * (raise + 1));

        if(v < t){check_desistir("DESISTIR", jogador_atual);}

        else if(v < 20*t){
            if(ultima_aposta >= getFichas()){
                aposta("APOSTAR TUDO", 0, jogador_atual);
            }
            else{aposta("CALL", ultima_aposta, jogador_atual);}
        }

        else if(v < 50*t){
            if(ultima_aposta >= getFichas()){
                aposta("APOSTAR TUDO", 0, jogador_atual);
            }
            else{aposta("AUMENTAR", 3*ultima_aposta, jogador_atual);}
        }

        else if(v < 100*t){
            if(ultima_aposta >= getFichas()){
                aposta("APOSTAR TUDO", 0, jogador_atual);
            }
            else{aposta("AUMENTAR", 12*ultima_aposta, jogador_atual);}
        }

        else if(v < 1000*t){
            if(ultima_aposta >= getFichas()){
                aposta("APOSTAR TUDO", 0, jogador_atual);
            }
            else{aposta("AUMENTAR", 33*ultima_aposta, jogador_atual);}
        }

        else{aposta("APOSTAR TUDO", ultima_aposta, jogador_atual);}
    }

    else if(getDificuldade() == 3){}
}

//GETTERS E SETTERS ---------------------------------------

int Computador::getDificuldade(){return _dificuldade;}
void Computador::setDificuldade(int dificuldade){_dificuldade = dificuldade;}

#endif