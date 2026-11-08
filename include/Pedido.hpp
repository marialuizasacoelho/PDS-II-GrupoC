#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <string>
#include <map>

class Pedido {
private:
    int id;
    std::string status;
    double valorTotal;
    std::string data;
    std::map<int, int> itens;

public:
    Pedido(int id, double valorTotal);

    Pedido(
        int id,
        double valorTotal,
        const std::map<int, int>& itens
    );

    void finalizar();
    void cancelar();

    std::string getStatus() const;
    int getId() const;
    double getValorTotal() const;
    std::string getData() const;

    const std::map<int, int>& getItens() const;
};

#endif