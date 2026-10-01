#ifndef CATALOGO_DE_PRODUTOS_HPP
#define CATALOGO_DE_PRODUTOS_HPP

#include <string>
#include <vector>

class CatalogoDeProdutos {
private:
    // atributos

public:
    /**
     * @brief Construtor do catálogo.
     */
    CatalogoDeProdutos();

    /**
     * @brief Adiciona um produto ao catálogo.
     * @param produto Produto a ser adicionado.
     */
    void adicionarProduto(/* Produto produto */);

    /**
     * @brief Remove um produto do catálogo.
     * @param id Identificador do produto.
     */
    void removerProduto(int id);

    /**
     * @brief Busca um produto pelo seu identificador.
     * @param id Identificador do produto.
     * @return Produto encontrado.
     */
    // Produto buscarProduto(int id);

    /**
     * @brief Exibe os produtos disponíveis no catálogo.
     */
    void listarProdutos();
};

#endif