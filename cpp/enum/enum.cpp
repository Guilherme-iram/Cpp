#pragma once
#include <iostream>
#include <string>
#include <map>

enum diaDaSemana : short int
{
    domingo, segunda, terca, quarta, quinta, sexta, sabado
};

enum class colocacao : short int
{
    primeiro, segundo, terceiro
};

void enumRun()
{
    short int aux;
    diaDaSemana diaSemana;
    colocacao podio;

    std::map<diaDaSemana, std::string> semana =
    {
    {domingo, "domingo",},
    {segunda, "segunda-feira",},
    {terca, "terca-feira",},
    {quarta, "quarta-feira",},
    {quinta, "quinta-feira",},
    {sexta, "sexta-feira",},
    {sabado, "sabado"}
    };

    std::map<colocacao, std::string> suaColocao =
    {
        {colocacao::primeiro, "primeiro lugar"},
        {colocacao::segundo, "segundo lugar"},
        {colocacao::terceiro, "terceiro lugar"}
    };

    std::cout << "VOCE VENCEU UM CAMPEONADO! ESTÁ NO PÓDIO!" << std::endl;
    std::cout << "Qual o dia da semana foi o campeonato? [0 - domingo, 1 - segunda ...] \n";
    std::cin >> aux;
    switch (aux)
    {
    case 0:
        diaSemana = domingo;
        break;
    case 1:
        diaSemana = segunda;
        break;
    case 2:
        diaSemana = terca;
        break;
    case 3:
        diaSemana = quarta;
        break;
    case 4:
        diaSemana = quinta;
        break;
    case 5:
        diaSemana = sexta;
        break;
    case 6:
        diaSemana = sabado;
        break;
    default:
        std::cout << "Valor invalido! Reinicie o programa ...";
        return;
    }

    std::cout << "Qual foi sua colocacao? [0 - primeiro, 1 - segundo, 2 - terceiro] \n";
    std::cin >> aux;
    switch (aux)
    {
    case 0:
        podio = colocacao::primeiro;
        break;
    case 1:
        podio = colocacao::segundo;
        break;
    case 2:
        podio = colocacao::terceiro;
        break;
    default:
        std::cout << "Valor invalido! Reinicie o programa ...";
        return;
    }

    std::cout << "\n" << semana[diaSemana] << "! Voce ficou em " << suaColocao[podio] << "!\n";

    return;

}

