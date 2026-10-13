#include "doctest.h"
#include "Carrinho.hpp"

TEST_CASE("Carrinho pode ser criado vazio") {
    Carrinho carrinho;

    CHECK(carrinho.calcularTotal() == doctest::Approx(0.0));
}

TEST_CASE("Carrinho permite adicionar e remover produtos") {
    Carrinho carrinho;

    CHECK_NOTHROW(carrinho.adicionarProduto(1, 2));
    CHECK_NOTHROW(carrinho.removerProduto(1));
}

TEST_CASE("Carrinho pode ser limpo") {
    Carrinho carrinho;

    carrinho.adicionarProduto(1, 2);
    CHECK_NOTHROW(carrinho.limpar());
}
