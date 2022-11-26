#ifndef MAO_CPP
#define MAO_CPP

#include "Mao.hpp"

#include <algorithm>
//TESTE ONLINE GDB
#include <iostream>

Mao::Mao(){std::vector<Carta> _mao;}

Mao::~Mao(){_mao.clear();}

void Mao::adiciona_carta(Carta carta){_mao.push_back(carta);}

std::string Mao::valor_mao(){retrun "Certo";}

//POSSIVEIS MAOS-----------------------------------------------------------------------------------------------------

int Mao::straight_flush(){

    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)}; //Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> pri_aux = {cartas_jogador.front()}; //Criando vector sem a primeira carta do jogador e com os mesmos naipes da primeira carta
    std::vector<Carta> seg_aux = {cartas_jogador.back()}; //Criando vector sem a segunda carta do jogador e com os mesmos naipes da segunda carta
    
    // Separando cartas por naipe para a primeira e segunda carta-----------------------------------------------------------------------------------------------
    for(int i=0; i<7; ++i){
        if(pri_aux.front().getNaipe() == _mao.at(i).getNaipe() && pri_aux.front().getValor() != _mao.at(i).getValor()){pri_aux.push_back(_mao.at(i));}
        else if(seg_aux.front().getNaipe() == _mao.at(i).getNaipe() && seg_aux.back().getValor() != _mao.at(i).getValor()){seg_aux.push_back(_mao.at(i));}
        else{continue;}
    }
    std::sort(pri_aux.begin(), pri_aux.end(), ordena_mao_valor); //Ordena maior para menor
    std::sort(seg_aux.begin(), seg_aux.end(), ordena_mao_valor); //Ordena maior para menor
    //----------------------------------------------------------------------------------------------------------------------------------------------------------

    if(pri_aux.front().getValor() == 13){
        Carta copia_um = pri_aux.front();
        copia_um.setValor(0);
        pri_aux.push_back(copia_um);
    }
    if(seg_aux.front().getValor() == 13 && seg_aux.front().getNaipe() != pri_aux.front().getNaipe()){
        Carta copia_dois = seg_aux.front();
        copia_dois.setValor(0);
        seg_aux.push_back(copia_dois);
    }

    int royal_flush[5] = {13, 12, 11, 10, 9};
    int pri_straight_flush[5]; //Array auxiliar
    int seg_straight_flush[5]; //Array auxiliar
    
    //Criando 2 maos de Royal Flush com a primeira e segunda carta do jogador, se der certo iguala a mao do jogador
    std::vector<Carta> aux_pri_royal_flush;
    std::vector<Carta> aux_seg_royal_flush;
    //Criando 2 maos de Straight Flush com a primeira e segunda carta do jogador, se der certo iguala a mao do jogador
    std::vector<Carta> aux_pri_straight_flush;
    std::vector<Carta> aux_seg_straight_flush;

    int confere_pri_royal_flush;
    int confere_seg_royal_flush;
    int confere_pri_straight_flush;
    int confere_seg_straight_flush;
    int it; //Iterator

    if(pri_aux.front().getValor() >= 4 || seg_aux.front().getValor() >= 4){ //Carta alta sempre tem que ser maior que 4 - menor sequencia possivel é 4 ,3 ,2 ,1 ,0 -> (5, 4, 3, 2, As)
        for(it=0; it<4; ++it){
            confere_pri_royal_flush = 0;
            confere_seg_royal_flush = 0;
            confere_pri_straight_flush = 0;
            confere_seg_straight_flush = 0;

            //Criando um Straight Flush para cada carta para comparar
            pri_straight_flush[0] = pri_aux.at(it).getValor();
            seg_straight_flush[0] = seg_aux.at(it).getValor();
            for(int j=1; j<5; ++j){
                pri_straight_flush[j] = pri_straight_flush[0] - j;
                seg_straight_flush[j] = seg_straight_flush[0] - j;}
            //------------------------------------------------------

            for(int j=0; j<5; ++j){
                if(pri_aux.at(it + j).getValor() ==  royal_flush[j]){
                    confere_pri_royal_flush += 1;
                    aux_pri_royal_flush.push_back(pri_aux.at(it + j));
                }
                else if(seg_aux.at(it + j).getValor() == royal_flush[j]){
                    confere_seg_royal_flush += 1;
                    aux_seg_royal_flush.push_back(seg_aux.at(it + j));
                }
                else if(pri_aux.at(it + j).getValor() ==  pri_straight_flush[j]){
                    confere_pri_straight_flush += 1;
                    aux_pri_straight_flush.push_back(pri_aux.at(it + j));
                }
                else if(seg_aux.at(it + j).getValor() == seg_straight_flush[j]){ 
                    confere_seg_straight_flush += 1;
                    aux_seg_straight_flush.push_back(seg_aux.at(j));
                }
                else{continue;}
            }
            
            if(confere_pri_royal_flush == 5){//Retorna o valor do Royal Flush se a sequencia tiver funcionado com a primeira carta
                int valor_mao = 270 + aux_pri_royal_flush.front().getValor();
                _mao = aux_pri_royal_flush;
                //Deleta todos vector's antes de sair
                cartas_jogador.clear(); pri_aux.clear(); seg_aux.clear(); aux_pri_royal_flush.clear(); aux_seg_royal_flush.clear(); aux_pri_straight_flush.clear(); aux_seg_straight_flush.clear();
                return valor_mao;
            }
            else if(confere_seg_royal_flush == 5){//Retorna o valor do Royal Flush se a sequencia tiver funcionado com a segunda carta
                int valor_mao = 270 + aux_seg_royal_flush.front().getValor();
                _mao = aux_seg_royal_flush;
                //Deleta todos vector's antes de sair
                cartas_jogador.clear(); pri_aux.clear(); seg_aux.clear(); aux_pri_royal_flush.clear(); aux_seg_royal_flush.clear(); aux_pri_straight_flush.clear(); aux_seg_straight_flush.clear();
                return valor_mao;
            }
            else if(confere_pri_straight_flush == 5){//Retorna o valor do Straight Flush se a sequencia tiver funcionado com a primeira carta
                int valor_mao = 240 + aux_pri_straight_flush.front().getValor();
                _mao = aux_pri_straight_flush;
                //Deleta todos vector's antes de sair
                cartas_jogador.clear(); pri_aux.clear(); seg_aux.clear(); aux_pri_royal_flush.clear(); aux_seg_royal_flush.clear(); aux_pri_straight_flush.clear(); aux_seg_straight_flush.clear();
                return valor_mao;
            }
            else if(confere_seg_straight_flush == 5){//Retorna o valor do Straight Flush se a sequencia tiver funcionado com a segunda carta
                int valor_mao = 240 + aux_seg_straight_flush.front().getValor();
                _mao = aux_seg_straight_flush;
                //Deleta todos vector's antes de sair
                cartas_jogador.clear(); pri_aux.clear(); seg_aux.clear(); aux_pri_royal_flush.clear(); aux_seg_royal_flush.clear(); aux_pri_straight_flush.clear(); aux_seg_straight_flush.clear();
                return valor_mao;
            }
            else{continue;}
        }
    }
    //Se as cartas mais altas forem menores que 4 - Deleta todos vector's e retorna o valor 0
    else{cartas_jogador.clear(); pri_aux.clear(); seg_aux.clear(); aux_pri_royal_flush.clear(); aux_seg_royal_flush.clear(); aux_pri_straight_flush.clear(); aux_seg_straight_flush.clear(); return 0;}

    //Se chegou aqui o jogador não tem um Straight Flush
    //Deleta todos os vectors e retorna 0
    cartas_jogador.clear(); pri_aux.clear(); seg_aux.clear(); aux_pri_royal_flush.clear(); aux_seg_royal_flush.clear(); aux_pri_straight_flush.clear(); aux_seg_straight_flush.clear(); 
    return 0;
}

int Mao::quadra(){

    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)}; //Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> mao_aux = _mao; //Criando vector auxiliar
    std::sort(mao_aux.begin(), mao_aux.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> quadra; //Criando vector que pode ser a mão final

    int confere_quadra = 0;
    int it; //Iterador

    for(it=0; it<3; ++it){
        quadra.erase(quadra.begin(), quadra.end());
        quadra.push_back(mao_aux.at(it));
        for(int j=0; j<5; ++j){
            if(mao_aux.at(it).getValor() == _mao.at(j).getValor() && mao_aux.at(it).getNaipe() != mao_aux.at(j).getNaipe()){
                confere_quadra += 1;
                quadra.push_back(_mao.at(j));
            }else{continue;}
        }


        if(confere_quadra == 4 && cartas_jogador.front().getValor() == quadra.front().getValor() || cartas_jogador.back().getValor() == quadra.front().getValor()){
            //Adicionando a carta kicker (Maior ou menor que a quadra)-----------------------------------------------------------------
            Carta maior(0, "", "", true); //Declarando a carta mais alta (precisa dos parâmetros por causa do construtor)
            int j, k; 

            for(j=0; j<7; ++j){ //Procurando a maior
                int confere_maior = 0;
                for(k=j+1; k<7; ++k){
                    if(mao_aux.at(j).getValor() > mao_aux.at(k).getValor() && mao_aux.at(j).getValor() > quadra.front().getValor()){
                        confere_maior += 1;
                        maior = mao_aux.at(j);
                    }
                    else{break;}
                }
                if(confere_maior == (7-k)){quadra.insert(quadra.begin(), maior);}
                else{continue;}
            }
            if(quadra.size() < 5){ //Não encontrou o kicker maior que a carta da quadra, então ela é menor
                for(j=0; j<7; ++j){ //Procurando a menor
                    int confere_maior = 0;
                    for(k=j+1; k<7; ++k){
                        if(_mao.at(j).getValor() > _mao.at(k).getValor() && _mao.at(j).getValor() < quadra.front().getValor()){
                            confere_maior += 1;
                            maior = mao_aux.at(j);
                        }
                        else{break;}
                    }
                if(confere_maior == (7-k)){quadra.push_back(maior);}
                else{continue;}
                }
            }
            //-------------------------------------------------------------------------------------------------------------------------
            
            int valor_mao = 210; // + quadra.front().getValor() + quadra.back().getValor();
            //Deleta todos vectors e a carta antes de sair
            cartas_jogador.clear(); mao_aux.clear(); quadra.clear(); maior.~Carta();
            return valor_mao;
        }
        else{cartas_jogador.clear(); mao_aux.clear(); quadra.clear(); return 0;}
    }
    //Se chegou até aqui o jogador não tem uma quadra
    cartas_jogador.clear(); mao_aux.clear(); quadra.clear(); 
    return 0;
}

/*int Mao::full_house(){

    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)}; //Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> mao_aux = _mao; //Criando vector auxiliar
    std::sort(mao_aux.begin(), mao_aux.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> trinca; //Criando um vector de tres cartas do mesmo valor
    std::vector<Carta> par; //Criando um vector de 2 cartas do mesmo valor

    int confere_cartas_iguais;

    for(int i=0; i<7; ++i){
        confere_cartas_iguais =0;
        for(int j=i+1; j<7; ++j){
            if(mao_aux.at(i).getValor() == mao_aux.at(j).getValor()){
                confere_cartas_iguais += 1;
            }
        }

        if(confere_cartas_iguais == 3){
            trinca.push_back(mao_aux.at(i));
            for(int j=i+1; j<5; ++j){
                if(mao_aux.at(i).getValor() == mao_aux.at(j).getValor()){
                    trinca.push_back(mao_aux.at(j));
                }
            }
        }else if(confere_cartas_iguais == 2){
            par.push_back(mao_aux.at(i));
            for(int j=i+1; j<5; ++j){
                if(mao_aux.at(i).getValor() == mao_aux.at(j).getValor()){
                    par.push_back(mao_aux.at(j));
                }
            }
        }
        if(trinca.size() >= 3 && par.size() == 2){break;}
    }
    std::vector<Carta> full_house = {trinca.begin(),}
}*/

int Mao::flush(){
    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)};//Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> pri_flus = {_mao.begin()+2, _mao.end()}; //Cartas da mesa
    std::sort(mao_mesa.begin(), mao_mesa.end(), ordena_mao_valor); //Ordena maior para menor
    
    std::vector<Carta> pri_flush = cartas_jogador;
    int confere_flush = 0;
    
    if(cartas_jogador.front().getNaipe() == cartas_jogador.back().getNaipe()){
        for(int i=0; i<5; ++i){
            if(cartas_jogador.front().getNaipe() == mao_mesa.at(i).getNaipe()){
                confere_flush += 1;
                mao_aux.push_back(mao_mesa.at(i));
            }else{continue;}
        }
        if(confere_flush == 5 && mao_aux.size() == 5){ 
            int valor_mao = 150;
            _mao = mao_aux;
            mao_aux.clear();
            mao_mesa.clear();
            cartas_jogador.clear();
            return valor_mao;
        }
    }
    else{cartas_jogador.clear(); mao_mesa.clear(); mao_aux.clear(); return 0;}
    
    if(confere_flush == 5 && mao_aux.size() < 5){cartas_jogador.clear(); mao_mesa.clear(); mao_aux.clear(); return 0;}
    else{cartas_jogador.clear(); mao_mesa.clear(); mao_aux.clear(); return 0;}
}
    
int Mao::straight(){
    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)}; //Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> mao_mesa = _mao; //Cartas da mesa
    std::sort(mao_mesa.begin(), mao_mesa.end(), ordena_mao_valor); //Ordena maior para menor
    
    std::vector<Carta> mao_aux = cartas_jogador;

    if(mao_mesa.front().getValor() == 13){
        Carta copia_aux = mao_mesa.front();
        copia_aux.setValor(0);
        mao_mesa.push_back(copia_aux); //Se a 1° for As cria uma copia, para uma possivel sequencia de As, 2, 3, 4, 5, e adiciona no vector com o valor 0
        copia_aux.~Carta();
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
                        confere_sequencia += 1;
                        mao_aux.push_back(mao_mesa.at(it + j));
                    }
                    else{break;}
                }
            }else{continue;}
            //Se for verdadeiro deleta todos vector's e retorna o valor do Straight + o valor das cartas do jogador
            if(confere_sequencia == 5 && mao_aux.size() == 5){
                int valor = 120;
                _mao = mao_aux;
                mao_aux.clear();
                mao_mesa.clear();
                cartas_jogador.clear();
                return valor;
            } 
            else{continue;}
        }
    }
    else{mao_aux.clear(); cartas_jogador.clear(); mao_mesa.clear(); return 0;}
    //Se ja fez todas iteracoes possiveis e o confere_sequencia menor que 5, jogador nao tem um Straight - Deleta todos vector's e retorna o valor 0
    if(it == 4 && confere_sequencia < 5){mao_aux.clear(); cartas_jogador.clear(); mao_mesa.clear(); return 0;}
}

int Mao::trinca(){
    std::vector<Carta> cartas_jogador = {_mao.front(), _mao.at(1)};//Cartas recebidas pelo jogador
    std::sort(cartas_jogador.begin(), cartas_jogador.end(), ordena_mao_valor); //Ordena maior para menor

    std::vector<Carta> mao_aux = _mao;

    std::vector<Carta> trinca_doisPares_par_cartaAlta;

    int confere_um = 1; //Tenho 1 carta, vou conferir se tenho mais
    int confere_dois = 1; //Tenho 1 carta, vou conferir se tenho mais
    int it; //iterator

    for(it = 0; it<6; ++it){
        for(int i=0; i<7; ++i){
            if(mao_aux.at(it).getNaipe() != mao_aux.at(i).getNaipe() && mao_aux.at(it).getValor() == mao_aux.at(i).getValor()){
                trinca_doisPares_par_cartaAlta.push_back(mao_aux.at(i));
                confere_um += 1;
            }
            else if(mao_aux.at(it+1).getNaipe() != mao_aux.at(i).getNaipe() && mao_aux.at(it).getValor() == mao_aux.at(i).getValor()){
                trinca_doisPares_par_cartaAlta.push_back(mao_aux.at(i));
                confere_dois += 1;
            }
            else{continue;}
        }
        int tamanho = trinca_doisPares_par_cartaAlta.size();
        int Valores[tamanho];
        std::string Naipes[tamanho];

        for(int j=0; j<tamanho; ++j){
            Valores[j] = trinca_doisPares_par_cartaAlta.at(j).getValor();
            Naipes[j] =  trinca_doisPares_par_cartaAlta.at(j).getNaipe();
        }

        int *pri_confere_valor_presente = std::find(Valores, Valores + tamanho, cartas_jogador.front().getValor());
        int *seg_confere_valor_presente = std::find(Valores, Valores + tamanho, cartas_jogador.back().getValor()); 

        if(cartas_jogador.front().getNaipe() == (*std::find(Naipes, Naipes + tamanho, cartas_jogador.front().getNaipe())) && cartas_jogador.back().getNaipe() == (*std::find(Naipes, Naipes + tamanho, cartas_jogador.back().getNaipe())) && pri_confere_valor_presente != Valores + tamanho && seg_confere_valor_presente != Valores + tamanho){
            if(confere_um == 3 || confere_dois == 3){
            int valor_mao = 90;
            _mao = trinca_doisPares_par_cartaAlta;
            trinca_doisPares_par_cartaAlta.clear();
            mao_aux.clear();
            cartas_jogador.clear();
            return valor_mao;
            }
            else if(confere_um == 2 && confere_dois == 2){
                int valor_mao = 60;
                _mao = trinca_doisPares_par_cartaAlta;
                mao_aux.clear();
                trinca_doisPares_par_cartaAlta.clear();
                cartas_jogador.clear();
                return valor_mao;
            }
            else if(confere_dois == 2 || confere_um == 2){
                int valor_mao = 30;
                _mao = trinca_doisPares_par_cartaAlta;
                mao_aux.clear();
                trinca_doisPares_par_cartaAlta.clear();
                cartas_jogador.clear();
                return valor_mao;
            }
            else{
                int valor_mao = 0;
                _mao = trinca_doisPares_par_cartaAlta;
                mao_aux.clear();
                trinca_doisPares_par_cartaAlta.clear();
                cartas_jogador.clear();
                return valor_mao;
            }
        }else{continue;}
    }
    if(it == 6 && trinca_doisPares_par_cartaAlta.size() > 5){mao_aux.clear(); trinca_doisPares_par_cartaAlta.clear(); cartas_jogador.clear(); return 0;}
}

int Mao::trinca(){}

int Mao::dois_pares(){}
    
int Mao::par(){}

int Mao::carta_alta(){}

//-------------------------------------------------------------------------------------------------------------------


//TESTE ONLINE GDB
void Mao::exibe_mao(){
    std::cout << "Sua mao: " << std::endl;
    for(std::vector<Carta>::iterator it = _mao.begin(); it != _mao.end(); ++it){
        it->exibe_carta();}
    std::cout << std::endl;
}

//GETTERS E AUXILIARES ---------------------------------------

bool Mao::ordena_mao_valor(Carta x, Carta y){return (x.getValor() >= y.getValor());}

std::vector<Carta> &Mao::getMao(){return _mao;}

#endif