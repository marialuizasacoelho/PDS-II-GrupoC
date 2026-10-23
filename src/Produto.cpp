#include "Produto.hpp"

Produto::Produto(int id, const std::string& nome, const std::string& descricao,
                 double preco, int estoque)
    : id(id),
      nome(nome),
      descricao(descricao),
      preco(preco),
      quantidadeEstoque(estoque) {
}

int Produto::getId() const {
    return id;
}

std::string Produto::getNome() const {
    return nome;
}

std::string Produto::getDescricao() const {
    return descricao;
}

double Produto::getPreco() const {
    return preco;
}

int Produto::getQuantidadeEstoque() const {
    return quantidadeEstoque;
}

bool Produto::estaDisponivel() const {
    return quantidadeEstoque > 0;
}

bool Produto::possuiEstoqueSuficiente(int qtd) const {
    return qtd >= 0 && quantidadeEstoque >= qtd;
}

void Produto::deduzirEstoque(int qtd) {
    if (qtd < 0 || qtd > quantidadeEstoque) {
        return;
    }

    quantidadeEstoque -= qtd;
}

void Produto::setQuantidadeEstoque(int novaQtd) {
    if (novaQtd < 0) {
        return;
    }

    quantidadeEstoque = novaQtd;
}