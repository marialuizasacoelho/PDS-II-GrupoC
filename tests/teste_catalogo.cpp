#include "doctest.h"
#include "CatalogoDeProdutos.hpp"
#include "Produto.hpp"

TEST_CASE("Catalogo de produtos pode ser criado") {
    CatalogoDeProdutos catalogo;

    CHECK_NOTHROW(catalogo.listarProdutos());
}

TEST_CASE("Catalogo permite remover um produto pelo ID") {
    CatalogoDeProdutos catalogo;

    CHECK_NOTHROW(catalogo.removerProduto(1));
}

TEST_CASE("Catalogo permite adicionar um produto") {
    CatalogoDeProdutos catalogo;
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    CHECK_NOTHROW(catalogo.adicionarProduto(produto));
}