#include "Pedido.hpp"

Pedido::Pedido(int id, double valorTotal)
    : id(id), status("Pendente"), valorTotal(valorTotal) {
}

void Pedido::finalizar() {
    if (status == "Pendente") {
        status = "Finalizado";
    }
}

void Pedido::cancelar() {
    if (status == "Pendente") {
        status = "Cancelado";
    }
}

std::string Pedido::getStatus() const {
    return status;
}

int Pedido::getId() const {
    return id;
}

double Pedido::getValorTotal() const {
    return valorTotal;
}
