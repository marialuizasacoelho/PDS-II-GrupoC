#include "CatalogoDeProdutos.hpp"

#include <iostream>
#include <algorithm>
#include <cctype>

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

std::vector<Produto*> CatalogoDeProdutos::buscarPorNome(
    const std::string& nome
) {
    std::vector<Produto*> encontrados;

    std::string termo = nome;

    std::transform(
        termo.begin(), termo.end(), termo.begin(),
        [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        }
    );

    for (auto& produto : produtos) {
        std::string nomeProduto = produto.getNome();

        std::transform(
            nomeProduto.begin(), nomeProduto.end(), nomeProduto.begin(),
            [](unsigned char c) {
                return static_cast<char>(std::tolower(c));
            }
        );

        if (nomeProduto.find(termo) != std::string::npos) {
            encontrados.push_back(&produto);
        }
    }

    return encontrados;
}

void CatalogoDeProdutos::listarProdutos() {
    if (produtos.empty()) {
        std::cout << "Nenhum produto cadastrado.\n";
        return;
    }

    for (const auto& produto : produtos) {
        std::cout << "ID: " << produto.getId()
                  << " | Nome: " << produto.getNome()
                  << " | Descricao: " << produto.getDescricao()
                  << " | Preco: R$ " << produto.getPreco()
                  << " | Estoque: " << produto.getQuantidadeEstoque()
                  << '\n';
    }
}