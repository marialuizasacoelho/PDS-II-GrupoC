#include "doctest.h"
#include "Cliente.hpp"
#include "Carrinho.hpp"
#include "Pedido.hpp"

TEST_CASE("Cliente armazena seus dados de usuario") {
    Cliente cliente(1, "Ana", "ana@example.com", "senha123");

    CHECK(cliente.getId() == 1);
    CHECK(cliente.getNome() == "Ana");
    CHECK(cliente.getEmail() == "ana@example.com");
}

TEST_CASE("Cliente nao possui privilegios de administrador") {
    Cliente cliente(1, "Ana", "ana@example.com", "senha123");

    CHECK_FALSE(cliente.ehAdmin());
}

TEST_CASE("Cliente possui um carrinho associado") {
    Cliente cliente(1, "Ana", "ana@example.com", "senha123");

    CHECK(cliente.getCarrinho() != nullptr);
}

TEST_CASE("Cliente pode adicionar pedidos ao historico") {
    Cliente cliente(1, "Ana", "ana@example.com", "senha123");
    Pedido pedido(10, 50.0);

    cliente.adicionarPedidoAoHistorico(&pedido);

    CHECK(cliente.getHistoricoPedidos().size() == 1);
    CHECK(cliente.getHistoricoPedidos()[0] == &pedido);
}
