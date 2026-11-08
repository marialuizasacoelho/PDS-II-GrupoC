#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <map>

class CatalogoDeProdutos;

class Carrinho {
private:
    std::map<int, int> produtos;

public:
    Carrinho();

    bool adicionarProduto(
        CatalogoDeProdutos& catalogo,
        int id,
        int quantidade
    );

    void removerProduto(int id);

    bool alterarQuantidade(
        CatalogoDeProdutos& catalogo,
        int id,
        int quantidade
    );

    double calcularTotal(CatalogoDeProdutos& catalogo) const;

    void visualizar(CatalogoDeProdutos& catalogo) const;

    void limpar();

    const std::map<int, int>& getProdutos() const;
};

#endif