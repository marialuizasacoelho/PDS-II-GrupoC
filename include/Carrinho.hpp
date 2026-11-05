#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <map>

class CatalogoDeProdutos;

class Carrinho {
private:
    std::map<int, int> produtos;

public:
    Carrinho();

    // Adiciona produto verificando existência e estoque.
    bool adicionarProduto(CatalogoDeProdutos& catalogo, int id, int quantidade);

    // Remove um produto pelo ID.
    void removerProduto(int id);

    // Calcula o valor total utilizando os preços do catálogo.
    double calcularTotal(CatalogoDeProdutos& catalogo) const;

    // Exibe os produtos e seus valores.
    void visualizar(CatalogoDeProdutos& catalogo) const;

    // Esvazia o carrinho.
    void limpar();

    // Permite consultar os produtos e quantidades armazenados.
    const std::map<int, int>& getProdutos() const;
};

#endif