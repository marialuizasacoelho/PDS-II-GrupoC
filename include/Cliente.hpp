#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Usuario.hpp"
#include <vector>

class Carrinho;
class Pedido;

/**
 * @file Cliente.hpp
 * @brief Definição da classe Cliente.
 */

/**
 * @class Cliente
 * @brief Representa um cliente da plataforma, capaz de gerenciar seu carrinho e histórico de pedidos.
 */
class Cliente : public Usuario {
private:
    Carrinho* carrinho;
    std::vector<Pedido*> historicoPedidos;

public:
    /**
     * @brief Construtor da classe Cliente.
     * @param id Identificador único.
     * @param nome Nome do cliente.
     * @param email E-mail de cadastro.
     * @param senha Senha de acesso.
     */
    Cliente(int id, const std::string& nome, const std::string& email, const std::string& senha);

    /**
     * @brief Destrutor da classe Cliente.
     */
    ~Cliente();

    /**
     * @brief Obtém o carrinho de compras do cliente.
     * @return Ponteiro para o objeto Carrinho.
     */
    Carrinho* getCarrinho() const;

    /**
     * @brief Adiciona um pedido ao histórico do cliente.
     * @param pedido Ponteiro para o pedido realizado.
     */
    void adicionarPedidoAoHistorico(Pedido* pedido);

    /**
     * @brief Retorna a lista de pedidos do cliente.
     * @return Vetor de ponteiros de Pedido.
     */
    std::vector<Pedido*> getHistoricoPedidos() const;

    /**
     * @brief Indica que esta conta não possui permissões administrativas.
     * @return Retorna sempre false.
     */
    bool ehAdmin() const override;
};

#endif // CLIENTE_HPP

