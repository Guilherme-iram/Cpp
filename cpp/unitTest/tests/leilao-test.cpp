#include ".././src/Avaliador.cpp"
#include "catch.hpp"

TEST_CASE("Leilao")
{
    SECTION("Leilao não pode receber 2 lances conssecutivos de um mesmo usuário")
    {
        Usuario manuel = Usuario("Manuel Godwithus");
        Lance primeiroLance(Usuario(manuel), 1000);
        Lance segundoLance(Usuario(manuel), 2000);
        Leilao leilao("Fiat 147 0Km");
        
        Avaliador leiloeiro;

        leilao.recebeLance(primeiroLance);
        leilao.recebeLance(segundoLance);
        leiloeiro.avalia(leilao);

        REQUIRE(leilao.recuperaLances().size() == 1);
        REQUIRE(leiloeiro.recuperaMaiorValor() == 1000);
    }
}
   