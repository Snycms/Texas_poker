#ifndef MAO_HPP
#define MAO_HPP

#include <vector>

class Mao{
  private:
    std::vector<Carta*> _mao;
  
  public:
    int comparar_mao(std::vector<Carta*> pri_mao; std::vector<Carta*> sec_mao);

#endif
