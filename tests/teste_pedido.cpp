#include "doctest.h"
#include "Pedido.hpp"

TEST_CASE("Pedido armazena ID e valor total") {
    Pedido pedido(10, 150.0);

    CHECK(pedido.getId() == 10);
    CHECK(pedido.getValorTotal() == doctest::Approx(150.0));
}

TEST_CASE("Pedido pode ser finalizado") {
    Pedido pedido(10, 150.0);

    CHECK_NOTHROW(pedido.finalizar());
}

TEST_CASE("Pedido pode ser cancelado") {
    Pedido pedido(11, 80.0);

    CHECK_NOTHROW(pedido.cancelar());
}

TEST_CASE("Finalizar e cancelar alteram o status do pedido") {
    Pedido finalizado(10, 150.0);
    Pedido cancelado(11, 80.0);

    finalizado.finalizar();
    cancelado.cancelar();

    CHECK(finalizado.getStatus() != cancelado.getStatus());
}
