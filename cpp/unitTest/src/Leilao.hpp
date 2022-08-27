#pragma once
#include <vector>
#include <string>
#include "Lance.cpp"

class Leilao
{
private:
    std::vector<Lance> lances;
    std::string descricao;
public:
    Leilao(std::string descricao);
    const std::vector<Lance>& recuperaLances() const;
    void recebeLance(const Lance& lance);
    void exibeDescricao();
};


