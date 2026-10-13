#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Produto.hpp"

TEST_CASE("Produto armazena corretamente seus dados") {
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    CHECK(produto.getId() == 1);
    CHECK(produto.getNome() == "Caderno");
    CHECK(produto.getDescricao() == "Caderno universitario");
    CHECK(produto.getPreco() == doctest::Approx(20.0));
    CHECK(produto.getQuantidadeEstoque() == 5);
}

TEST_CASE("Produto informa se esta disponivel para compra") {
    Produto comEstoque(1, "Caderno", "Caderno universitario", 20.0, 5);
    Produto semEstoque(2, "Caneta", "Caneta azul", 3.0, 0);

    CHECK(comEstoque.estaDisponivel() == true);
    CHECK(semEstoque.estaDisponivel() == false);
}

TEST_CASE("Produto verifica se possui estoque suficiente") {
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    CHECK(produto.possuiEstoqueSuficiente(3) == true);
    CHECK(produto.possuiEstoqueSuficiente(5) == true);
    CHECK(produto.possuiEstoqueSuficiente(6) == false);
}

TEST_CASE("Produto deduz a quantidade vendida do estoque") {
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    produto.deduzirEstoque(2);

    CHECK(produto.getQuantidadeEstoque() == 3);
}

TEST_CASE("Produto permite atualizar a quantidade em estoque") {
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    produto.setQuantidadeEstoque(10);

    CHECK(produto.getQuantidadeEstoque() == 10);
}
