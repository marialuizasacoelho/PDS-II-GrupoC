#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Usuario.hpp"

class CatalogoDeProdutos;
class Produto;

/**
 * @file Administrador.hpp
 * @brief Definição da classe Administrador.
 */

/**
 * @class Administrador
 * @brief Representa um usuário com privilégios de gestão de produtos e estoque.
 */
class Administrador : public Usuario {
public:
    /**
     * @brief Construtor da classe Administrador.
     * @param id Identificador único.
     * @param nome Nome do administrador.
     * @param email E-mail.
     * @param senha Senha de acesso.
     */
    Administrador(int id, const std::string& nome, const std::string& email, const std::string& senha);

    /**
     * @brief Cadastra um novo produto no catálogo do sistema.
     * @param catalogo Referência do catálogo do sistema.
     * @param produto Instância do produto a ser cadastrado.
     */
    void cadastrarProduto(CatalogoDeProdutos& catalogo, const Produto& produto);

    /**
     * @brief Remove um produto do catálogo pelo ID.
     * @param catalogo Referência do catálogo.
     * @param idProduto ID do produto a remover.
     */
    void removerProduto(CatalogoDeProdutos& catalogo, int idProduto);

    /**
     * @brief Atualiza a quantidade em estoque de um produto.
     * @param produto Ponteiro do produto.
     * @param novaQuantidade Nova quantidade em estoque.
     */
    void atualizarEstoqueProduto(Produto* produto, int novaQuantidade);

    /**
     * @brief Indica que esta conta possui privilégios administrativos.
     * @return Retorna sempre true.
     */
    bool ehAdmin() const override;
};

#endif // ADMINISTRADOR_HPP
