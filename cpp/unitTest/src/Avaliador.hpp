#pragma once
#include "Leilao.cpp"

class Avaliador
{
private:
    float maiorValor = 0;
public:
    void avalia(Leilao);
    float recuperaMaiorValor() const;
};


