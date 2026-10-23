#include "CatalogoDeProdutos.hpp"

#include <iostream>

CatalogoDeProdutos::CatalogoDeProdutos() : produtos() {
}

void CatalogoDeProdutos::adicionarProduto(const Produto& produto) {
    if (buscarProduto(produto.getId()) == nullptr) {
        produtos.push_back(produto);
    }
}

void CatalogoDeProdutos::removerProduto(int id) {
    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->getId() == id) {
            produtos.erase(it);
            return;
        }
    }
}

Produto* CatalogoDeProdutos::buscarProduto(int id) {
    for (auto& produto : produtos) {
        if (produto.getId() == id) {
            return &produto;
        }
    }

    return nullptr;
}

void CatalogoDeProdutos::listarProdutos() {
    for (const auto& produto : produtos) {
        std::cout << "ID: " << produto.getId()
                  << " | Nome: " << produto.getNome()
                  << " | Preço: " << produto.getPreco()
                  << " | Estoque: " << produto.getQuantidadeEstoque()
                  << '\n';
    }
}
