#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <string>

class Pedido {
private:
    int id;
    std::string status;
    double valorTotal;

public:
    /**
     * @brief Cria um novo pedido.
     * @param id Identificador do pedido.
     * @param valorTotal Valor total do pedido.
     */
    Pedido(int id, double valorTotal);

    /**
     * @brief Finaliza o pedido.
     */
    void finalizar();

    /**
     * @brief Cancela o pedido.
     */
    void cancelar();

    /**
     * @brief Consulta o status atual do pedido.
     * @return Status do pedido.
     */
    std::string getStatus() const;

    /**
     * @brief Obtém o identificador do pedido.
     * @return ID do pedido.
     */
    int getId() const;

    /**
     * @brief Obtém o valor total do pedido.
     * @return Valor total.
     */
    double getValorTotal() const;
};

#endif