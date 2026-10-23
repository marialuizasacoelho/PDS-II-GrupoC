#ifndef CATALOGO_DE_PRODUTOS_HPP
#define CATALOGO_DE_PRODUTOS_HPP

#include <vector>
#include "Produto.hpp"

class CatalogoDeProdutos {
private:
    std::vector<Produto> produtos;

public:
    CatalogoDeProdutos();

    void adicionarProduto(const Produto& produto);
    void removerProduto(int id);
    Produto* buscarProduto(int id);
    void listarProdutos();
};

#endif
