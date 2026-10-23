
#include "Administrador.hpp"
#include "CatalogoDeProdutos.hpp"
#include "Produto.hpp"

Administrador::Administrador(int id, const std::string& nome,
                             const std::string& email,
                             const std::string& senha)
    : Usuario(id, nome, email, senha) {
}

void Administrador::cadastrarProduto(CatalogoDeProdutos& catalogo,
                                     const Produto& produto) {
    catalogo.adicionarProduto(produto);
}

void Administrador::removerProduto(CatalogoDeProdutos& catalogo,
                                   int idProduto) {
    catalogo.removerProduto(idProduto);
}

void Administrador::atualizarEstoqueProduto(Produto* produto,
                                            int novaQuantidade) {
    if (produto != nullptr && novaQuantidade >= 0) {
        produto->setQuantidadeEstoque(novaQuantidade);
    }
}

bool Administrador::ehAdmin() const {
    return true;
}
