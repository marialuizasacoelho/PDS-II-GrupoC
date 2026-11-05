#include "doctest.h"
#include "Carrinho.hpp"
#include "CatalogoDeProdutos.hpp"
#include "Produto.hpp"

TEST_CASE("Carrinho pode ser criado vazio") {
    Carrinho carrinho;

    CHECK(carrinho.getProdutos().empty());
}

TEST_CASE("Carrinho adiciona produto existente") {
    CatalogoDeProdutos catalogo;
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    catalogo.adicionarProduto(produto);

    Carrinho carrinho;

    CHECK(carrinho.adicionarProduto(catalogo, 1, 2));
    CHECK(carrinho.getProdutos().at(1) == 2);
}

TEST_CASE("Carrinho acumula quantidades do mesmo produto") {
    CatalogoDeProdutos catalogo;
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    catalogo.adicionarProduto(produto);

    Carrinho carrinho;

    CHECK(carrinho.adicionarProduto(catalogo, 1, 2));
    CHECK(carrinho.adicionarProduto(catalogo, 1, 1));

    CHECK(carrinho.getProdutos().at(1) == 3);
}

TEST_CASE("Carrinho rejeita produto inexistente") {
    CatalogoDeProdutos catalogo;
    Carrinho carrinho;

    CHECK_FALSE(carrinho.adicionarProduto(catalogo, 99, 1));
    CHECK(carrinho.getProdutos().empty());
}

TEST_CASE("Carrinho rejeita quantidade superior ao estoque") {
    CatalogoDeProdutos catalogo;
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    catalogo.adicionarProduto(produto);

    Carrinho carrinho;

    CHECK_FALSE(carrinho.adicionarProduto(catalogo, 1, 6));
    CHECK(carrinho.getProdutos().empty());
}

TEST_CASE("Carrinho verifica estoque ao acumular produtos") {
    CatalogoDeProdutos catalogo;
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    catalogo.adicionarProduto(produto);

    Carrinho carrinho;

    CHECK(carrinho.adicionarProduto(catalogo, 1, 3));
    CHECK_FALSE(carrinho.adicionarProduto(catalogo, 1, 3));

    CHECK(carrinho.getProdutos().at(1) == 3);
}

TEST_CASE("Carrinho calcula corretamente o valor total") {
    CatalogoDeProdutos catalogo;

    Produto caderno(1, "Caderno", "Caderno universitario", 20.0, 5);
    Produto caneta(2, "Caneta", "Caneta azul", 3.0, 10);

    catalogo.adicionarProduto(caderno);
    catalogo.adicionarProduto(caneta);

    Carrinho carrinho;

    carrinho.adicionarProduto(catalogo, 1, 2);
    carrinho.adicionarProduto(catalogo, 2, 3);

    CHECK(carrinho.calcularTotal(catalogo) == doctest::Approx(49.0));
}

TEST_CASE("Carrinho permite remover produtos") {
    CatalogoDeProdutos catalogo;
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    catalogo.adicionarProduto(produto);

    Carrinho carrinho;

    carrinho.adicionarProduto(catalogo, 1, 2);
    carrinho.removerProduto(1);

    CHECK(carrinho.getProdutos().empty());
}

TEST_CASE("Carrinho pode ser limpo") {
    CatalogoDeProdutos catalogo;
    Produto produto(1, "Caderno", "Caderno universitario", 20.0, 5);

    catalogo.adicionarProduto(produto);

    Carrinho carrinho;

    carrinho.adicionarProduto(catalogo, 1, 2);
    carrinho.limpar();

    CHECK(carrinho.getProdutos().empty());
}