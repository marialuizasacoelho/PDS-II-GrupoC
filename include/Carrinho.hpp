#ifndef CARRINHO_HPP
#define CARRINHO_HPP

class Carrinho {
private:
    // produtos adicionados
    // quantidade
    // valor total

public:
    /**
     * @brief Constrói um carrinho vazio.
     */
    Carrinho();

    /**
     * @brief Adiciona um produto ao carrinho.
     * @param id Identificador do produto.
     * @param quantidade Quantidade desejada.
     */
    void adicionarProduto(int id, int quantidade);

    /**
     * @brief Remove um produto do carrinho.
     * @param id Identificador do produto.
     */
    void removerProduto(int id);

    /**
     * @brief Calcula o valor total da compra.
     * @return Valor total do carrinho.
     */
    double calcularTotal();

    /**
     * @brief Esvazia o carrinho.
     */
    void limpar();

    /**
     * @brief Exibe os produtos presentes no carrinho.
     */
    void visualizar();
};

#endif