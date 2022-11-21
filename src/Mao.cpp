#ifndef MAO_CPP
#define MAO_CPP

#include "Mao.hpp"

#include <algorithm>
//TESTE ONLINE GDB
#include <iostream>

Mao::Mao(){std::vector<Carta> _mao;}

Mao::~Mao(){_mao.clear();}

void Mao::adiciona_carta(Carta carta){_mao.push_back(carta);}

Carta Mao::maior_carta(){
    Carta maior = _mao.front();
    for(std::vector<Carta>::iterator it = _mao.begin(); it != _mao.end(); ++it){
        if(maior.getValor() <= it->getValor()){
            maior = *it;
        }
    }
    return maior;
}

int Mao::valor_mao(){
    std::cout << royal_flush() << std::endl;
    return 0;
}

//POSSIVEIS MAOS-----------------------------------------------------------------------------------------------------

int Mao::royal_flush(){
    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)}; //Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena da maior para menor

    std::vector<Carta> mao_mesa = _mao; //Cartas da mesa
    std::sort(mao_mesa.begin(), mao_mesa.end(), ordena_mao_valor); //Ordena da maior para menor
    
    int Royal_Flush[5] = {13, 12, 11, 10, 9}; //Array auxiliar
    int confere_iguais = 0;
    
    //Se as duas cartas_jogador forem as ultimas da mao_mesa o jogador não tem um Royal Flush
    if(cartas_jogador.front().getValor() != mao_mesa.at(5).getValor() && cartas_jogador.back().getValor() != mao_mesa.at(6).getValor()){ 
        for(int i=0; i<5; ++i){
            //Conferindo se os valores são iguais aos do array Royal Flush e se os naipes são iguais, se não o jogador não tem um Royal Flush
            if(mao_mesa.at(i).getValor() == Royal_Flush[i] && mao_mesa.at(0).getNaipe() == mao_mesa.at(i).getNaipe()){
                confere_iguais += 1;
            }
            else{break;}
        }
        if(confere_iguais == 5){ //Se isso for verdade mao_mesa é igual ao Royal Flush
            mao_mesa.clear();
            cartas_jogador.clear();
            return 20;}
        else{ //Não tem um Royal Flush
            mao_mesa.clear();
            cartas_jogador.clear();
            return 0;}
    }
    else{ //Não tem um Royal Flush
        mao_mesa.clear();
        cartas_jogador.clear();
        return 0;}
}

int Mao::straight_flush(){
    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)}; //Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> mao_mesa = _mao; //Cartas da mesa
    std::sort(mao_mesa.begin(), mao_mesa.end(), ordena_mao_valor); //Ordena maior para menor

    if(mao_mesa.front().getValor() == 13){mao_mesa.front().setValor(0);} //Se a 1° for As ele terá valor 0, para uma sequencia de As, 2, 3, 4, 5
    std::sort(mao_mesa.begin(), mao_mesa.end(), ordena_mao_valor); //Ordena de novo

    int confere_sequencia;
    int Straight_Flush[5]; 
    int it; //Iterator

    if(mao_mesa.front().getValor() > 4){ //Carta alta sempre tem que ser maior que 4 - menor sequencia possivel é 4 ,3 ,2 ,1 ,0 -> (5, 4, 3, 2, As)
        for(it=0; it<3; ++it){
            confere_sequencia = 0;
            Straight_Flush[0] = mao_mesa.at(it).getValor();

            for(int j=1; j<5; ++j){Straight_Flush[j] = Straight_Flush[0] - j;} //Criando um Straight Flush para comparar

            int *pri_elemento = std::find(Straight_Flush, Straight_Flush + 5, cartas_jogador.front().getValor());
            int *seg_elemento = std::find(Straight_Flush, Straight_Flush + 5, cartas_jogador.back().getValor()); 
            
            if(pri_elemento != Straight_Flush + 5 && seg_elemento != Straight_Flush + 5){
                for(int j=0; j<5; ++j){
                    if(mao_mesa.at(it + j).getValor() == Straight_Flush[j] && mao_mesa.at(it).getNaipe() == mao_mesa.at(it + j).getNaipe()){ 
                        confere_sequencia += 1;}
                    else{break;}
                }
            }else{continue;}
            
            if(confere_sequencia == 5){cartas_jogador.clear(); mao_mesa.clear(); return 18;} //Deleta todos vector's e retorna o valor do Straight Flush
            else{continue;}
        }
    }
    else{cartas_jogador.clear(); mao_mesa.clear(); return 0;} //Deleta todos vector's e retorna o valor 0
    //Se ja fez todas iteracoes possiveis e o confere_sequencia menor que 5, jogador nao tem um Straight Flush - Deleta todos vector's e retorna o valor 0
    if(it == 3 && confere_sequencia < 5){cartas_jogador.clear(); mao_mesa.clear(); return 0;} 
}

/*int Mao::quadra(){
    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)}; //Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> mao_mesa = _mao; //Cartas da mesa
    std::sort(mao_mesa.begin(), mao_mesa.end(), ordena_mao_valor); //Ordena maior para menor

    int confere_quadra;

}*/

int Mao::full_house(){}

int Mao::flush(){}
    
int Mao::straight(){
    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)}; //Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> mao_mesa = _mao; //Cartas da mesa
    std::sort(mao_mesa.begin(), mao_mesa.end(), ordena_mao_valor); //Ordena maior para menor

    Carta copia_aux = mao_mesa.front();
    if(copia_aux.getValor() == 13){
        copia_aux.setValor(0);
        mao_mesa.push_back(copia_aux); //Se a 1° for As cria uma copia, para uma possivel sequencia de As, 2, 3, 4, 5, e adiciona no vector com o valor 0
    }

    int confere_sequencia;
    int Straight[5]; 
    int it; //Iterator

    if(mao_mesa.front().getValor() > 4){ //Carta alta sempre tem que ser maior que 4 - menor sequencia possivel é 4 ,3 ,2 ,1 ,0 -> (5, 4, 3, 2, As)
        for(it=0; it<4; ++it){
            confere_sequencia = 0;

            Straight[0] = mao_mesa.at(it).getValor();
            for(int j=1; j<5; ++j){Straight[j] = Straight[0] - j;} //Criando um Straight para comparar
            
            int *pri_elemento = std::find(Straight, Straight + 5, cartas_jogador.front().getValor());
            int *seg_elemento = std::find(Straight, Straight + 5, cartas_jogador.back().getValor()); 
            
            if(pri_elemento != Straight + 5 && seg_elemento != Straight + 5){
                for(int j=0; j<5; ++j){
                    if(mao_mesa.at(it + j).getValor() == Straight[j]){ 
                        confere_sequencia += 1;}
                    else{break;}
                }
            }else{continue;}

            if(confere_sequencia == 5){cartas_jogador.clear(); mao_mesa.clear(); return 10;} //Deleta todos vector's e retorna o valor do Straight
            else{continue;}
        }
    }
    else{cartas_jogador.clear(); mao_mesa.clear(); return 0;}
    //Se ja fez todas iteracoes possiveis e o confere_sequencia menor que 5, jogador nao tem um Straight - Deleta todos vector's e retorna o valor 0
    if(it == 4 && confere_sequencia < 5){cartas_jogador.clear(); mao_mesa.clear(); return 0;}
}
    
int Mao::trinca(){}

int Mao::dois_pares(){}

int Mao::par(){}

//-------------------------------------------------------------------------------------------------------------------


//TESTE ONLINE GDB
void Mao::exibe_mao(){
    std::cout << "Sua mao: " << std::endl;
    for(std::vector<Carta>::iterator it = _mao.begin(); it != _mao.end(); ++it){
        it->exibe_carta();}
    std::cout << std::endl;
}

//GETTERS E AUXILIARES ---------------------------------------

bool Mao::ordena_mao_valor(Carta x, Carta y){return (x.getValor() > y.getValor());}

std::vector<Carta> &Mao::getMao(){return _mao;}


#endif