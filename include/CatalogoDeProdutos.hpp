#ifndef CATALOGO_DE_PRODUTOS_HPP
#define CATALOGO_DE_PRODUTOS_HPP

#include <vector>
#include <string>
#include "Produto.hpp"

class CatalogoDeProdutos {
private:
    std::vector<Produto> produtos;

public:
    CatalogoDeProdutos();

    void adicionarProduto(const Produto& produto);
    void removerProduto(int id);
    Produto* buscarProduto(int id);

    std::vector<Produto*> buscarPorNome(const std::string& nome);

    void listarProdutos();
};

#endif