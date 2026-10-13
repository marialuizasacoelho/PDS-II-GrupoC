#include "doctest.h"
#include "CatalogoDeProdutos.hpp"

TEST_CASE("Catalogo de produtos pode ser criado") {
    CatalogoDeProdutos catalogo;

    CHECK_NOTHROW(catalogo.listarProdutos());
}

TEST_CASE("Catalogo permite remover um produto pelo ID") {
    CatalogoDeProdutos catalogo;

    CHECK_NOTHROW(catalogo.removerProduto(1));
}

TEST_CASE("Catalogo permite chamar a operacao de adicao") {
    CatalogoDeProdutos catalogo;

    CHECK_NOTHROW(catalogo.adicionarProduto());
}
