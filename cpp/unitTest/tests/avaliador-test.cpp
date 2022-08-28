#include ".././src/Avaliador.cpp"
#include "catch.hpp"



Leilao emOrdemCrescente()
{
    // Arrange - Given
    Lance primeiroLance(Usuario("Carlos Eduardo"), 1000);
    Lance segundoLance(Usuario("Ana Maria"), 2000);
    Leilao leilao("Fiat 147 0Km");

    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    return leilao;
}

Leilao emOrdemDecrescente()
{
    // Arrange - Given
    Lance primeiroLance(Usuario("Carlos Eduardo"), 2000);
    Lance segundoLance(Usuario("Ana Maria"), 1000);
    Leilao leilao("Fiat 147 0Km");

    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    return leilao;
}

TEST_CASE("Avaliador")
{
    Avaliador leiloeiro;
    SECTION("Ordenacao")
    {
        SECTION("Maior valor de lance")
        {
            // Arrange - Given
            Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());
            
            // Act - When
            leiloeiro.avalia(leilao);

            // Assert - Then
            REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
        }

        SECTION("Menor valor de lance")
        {
            // Arrange - Given
            Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());
            
            // Act - When
            leiloeiro.avalia(leilao);

            // Assert - Then
            REQUIRE(1000 == leiloeiro.recuperaMenorValor());
        }
    }
    

    SECTION("3 maiores lances")
    {
    // Arrange - Given
    Lance primeiroLance(Usuario("Carlos Eduardo"), 2000);
    Lance segundoLance(Usuario("Ana Maria"), 1000);
    Lance terceiroLance(Usuario("Thereza Chistina"), 3000);
    Lance quartoLance(Usuario("Max Red"), 500);
    Leilao leilao("Fiat 147 0Km");

    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    leilao.recebeLance(terceiroLance);
    leilao.recebeLance(quartoLance);

    // Act - When
    leiloeiro.avalia(leilao);
    std::vector<Lance> maiores3valores = leiloeiro.recupera3MaioresLances();
    
    // Assert - Then
    REQUIRE(3 == maiores3valores.size());
    REQUIRE(3000 == maiores3valores[0].recuperaValor());
    REQUIRE(2000 == maiores3valores[1].recuperaValor());
    REQUIRE(1000 == maiores3valores[2].recuperaValor());
    }
}
