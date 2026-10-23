#include "Cliente.hpp"
#include "Carrinho.hpp"
#include "Pedido.hpp"

Cliente::Cliente(int id, const std::string& nome,
                 const std::string& email, const std::string& senha)
    : Usuario(id, nome, email, senha),
      carrinho(new Carrinho()),
      historicoPedidos() {
}

Cliente::~Cliente() {
    delete carrinho;
}

Carrinho* Cliente::getCarrinho() const {
    return carrinho;
}

void Cliente::adicionarPedidoAoHistorico(Pedido* pedido) {
    if (pedido != nullptr) {
        historicoPedidos.push_back(pedido);
    }
}

std::vector<Pedido*> Cliente::getHistoricoPedidos() const {
    return historicoPedidos;
}

bool Cliente::ehAdmin() const {
    return false;
}