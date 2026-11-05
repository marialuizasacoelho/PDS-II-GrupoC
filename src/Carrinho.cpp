#include "Carrinho.hpp"
#include "CatalogoDeProdutos.hpp"
#include "Produto.hpp"

#include <iostream>
#include <iomanip>

Carrinho::Carrinho() : produtos() {
}

bool Carrinho::adicionarProduto(
    CatalogoDeProdutos& catalogo,
    int id,
    int quantidade
) {
    if (id < 0 || quantidade <= 0) {
        return false;
    }

    Produto* produto = catalogo.buscarProduto(id);

    if (produto == nullptr) {
        return false;
    }

    int quantidadeAtual = 0;

    auto it = produtos.find(id);

    if (it != produtos.end()) {
        quantidadeAtual = it->second;
    }

    int estoqueDisponivel = produto->getQuantidadeEstoque();

    if (quantidadeAtual > estoqueDisponivel ||
        quantidade > estoqueDisponivel - quantidadeAtual) {
        return false;
    }

    produtos[id] += quantidade;

    return true;
}

void Carrinho::removerProduto(int id) {
    produtos.erase(id);
}

double Carrinho::calcularTotal(
    CatalogoDeProdutos& catalogo
) const {
    double total = 0.0;

    for (const auto& item : produtos) {
        Produto* produto = catalogo.buscarProduto(item.first);

        if (produto == nullptr) {
            return 0.0;
        }

        total += produto->getPreco() * item.second;
    }

    return total;
}

void Carrinho::visualizar(
    CatalogoDeProdutos& catalogo
) const {
    if (produtos.empty()) {
        std::cout << "Carrinho vazio.\n";
        return;
    }

    std::cout << "\n===== SEU CARRINHO =====\n";

    for (const auto& item : produtos) {
        Produto* produto = catalogo.buscarProduto(item.first);

        if (produto == nullptr) {
            std::cout << "Produto ID " << item.first
                      << " nao encontrado no catalogo.\n";
            continue;
        }

        double subtotal = produto->getPreco() * item.second;

        std::cout << "Produto: " << produto->getNome()
                  << " | Quantidade: " << item.second
                  << " | Preco unitario: R$ "
                  << std::fixed << std::setprecision(2)
                  << produto->getPreco()
                  << " | Subtotal: R$ " << subtotal
                  << '\n';
    }

    std::cout << "-----------------------------\n";
    std::cout << "TOTAL: R$ "
              << std::fixed << std::setprecision(2)
              << calcularTotal(catalogo)
              << '\n';
}

void Carrinho::limpar() {
    produtos.clear();
}

const std::map<int, int>& Carrinho::getProdutos() const {
    return produtos;
}