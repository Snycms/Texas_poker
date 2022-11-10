#ifndef CARTAS_HPP
#define CARTAS_HPP

#include <string>

class Carta{
    private:
        int _valor;
        std::string _tipo;
        bool _esta_virada;

    public:
        Carta(int valor; std::string tipo; bool esta_virada);

        int comparar_carta();

        void virar(bool Esta_virada);

        //Getters

        int getValor();
        std::string getTipo();
        bool getEsta_virada

}

#endif