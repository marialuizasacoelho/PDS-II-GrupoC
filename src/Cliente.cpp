#include "Cliente.hpp"
#include "Carrinho.hpp"
#include "Pedido.hpp"
#include <stdexcept>

Cliente::Cliente(int id, const std::string& nome,
                 const std::string& email, const std::string& senha)
    : Usuario(id, nome, email, senha),
      carrinho(new Carrinho()),
      historicoPedidos() {
    
    if (id <= 0) {
        throw std::invalid_argument("ID do cliente deve ser um numero positivo.");
    }
    if (nome.empty()) {
        throw std::invalid_argument("Nome do cliente nao pode ser vazio.");
    }
    if (email.empty()) {
        throw std::invalid_argument("Email do cliente nao pode ser vazio.");
    }
}

Cliente::~Cliente() {
    delete carrinho;
    
    for (Pedido* pedido : historicoPedidos) {
        delete pedido;
    }
    historicoPedidos.clear();
}

Carrinho* Cliente::getCarrinho() const {
    return carrinho;
}

void Cliente::adicionarPedidoAoHistorico(Pedido* pedido) {
    if (pedido == nullptr) {
        throw std::invalid_argument("Nao e possivel adicionar um pedido nulo ao historico.");
    }
    historicoPedidos.push_back(pedido);
}

std::vector<Pedido*> Cliente::getHistoricoPedidos() const {
    return historicoPedidos;
}

bool Cliente::ehAdmin() const {
    return false;
}
