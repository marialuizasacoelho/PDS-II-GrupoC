#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

/**
 * @file Produto.hpp
 * @brief Definição da classe Produto.
 */

/**
 * @class Produto
 * @brief Representa um item comercializado na plataforma de e-commerce.
 */
class Produto {
private:
    int id;
    std::string nome;
    std::string descricao;
    double preco;
    int quantidadeEstoque;

public:
    /**
     * @brief Construtor da classe Produto.
     * @param id ID único do produto.
     * @param nome Nome do produto.
     * @param descricao Descrição sumária.
     * @param preco Preço unitário.
     * @param estoque Quantidade inicial em estoque.
     */
    Produto(int id, const std::string& nome, const std::string& descricao, double preco, int estoque);

    int getId() const;
    std::string getNome() const;
    std::string getDescricao() const;
    double getPreco() const;
    int getQuantidadeEstoque() const;

    /**
     * @brief Verifica se o produto está disponível em estoque.
     * @return true se estoque > 0, false caso contrário.
     */
    bool estaDisponivel() const;

    /**
     * @brief Checa se há uma quantidade suficiente para atender ao pedido.
     * @param qtd Solicitada.
     * @return true se quantidadeEstoque >= qtd.
     */
    bool possuiEstoqueSuficiente(int qtd) const;

    /**
     * @brief Reduz a quantidade em estoque após a confirmação de uma compra.
     * @param qtd Vendida.
     */
    void deduzirEstoque(int qtd);

    /**
     * @brief Define uma nova quantidade para o estoque do produto.
     * @param novaQtd Nova quantidade disponível.
     */
    void setQuantidadeEstoque(int novaQtd);
};

#endif // PRODUTO_HPP
