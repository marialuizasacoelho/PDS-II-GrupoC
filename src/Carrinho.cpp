#include "Carrinho.hpp"

Carrinho::Carrinho() : produtos() {
}

void Carrinho::adicionarProduto(int id, int quantidade) {
    if (id < 0 || quantidade <= 0) {
        return;
    }

    produtos[id] += quantidade;
}

void Carrinho::removerProduto(int id) {
    produtos.erase(id);
}

double Carrinho::calcularTotal() {
    // O contrato atual não fornece os preços dos produtos.
    // Portanto, não é possível calcular um total monetário real.
    return 0.0;
}

void Carrinho::limpar() {
    produtos.clear();
}

void Carrinho::visualizar() {
    for (const auto& item : produtos) {
        // Exibe o ID do produto e a quantidade.
        // O nome e o preço dependem do catálogo.
        (void)item;
    }
}
