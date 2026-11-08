#include "Pedido.hpp"

#include <ctime>
#include <sstream>
#include <iomanip>

namespace {

std::string dataAtual() {
    std::time_t agora = std::time(nullptr);
    std::tm* dataLocal = std::localtime(&agora);

    std::ostringstream saida;

    if (dataLocal) {
        saida << std::put_time(dataLocal, "%d/%m/%Y");
    }

    return saida.str();
}

}

Pedido::Pedido(int id, double valorTotal)
    : id(id),
      status("Pendente"),
      valorTotal(valorTotal),
      data(dataAtual()),
      itens() {
}

Pedido::Pedido(
    int id,
    double valorTotal,
    const std::map<int, int>& itens
)
    : id(id),
      status("Pendente"),
      valorTotal(valorTotal),
      data(dataAtual()),
      itens(itens) {
}

void Pedido::finalizar() {
    if (status == "Pendente") {
        status = "Finalizado";
    }
}

void Pedido::cancelar() {
    if (status == "Pendente") {
        status = "Cancelado";
    }
}

std::string Pedido::getStatus() const {
    return status;
}

int Pedido::getId() const {
    return id;
}

double Pedido::getValorTotal() const {
    return valorTotal;
}

std::string Pedido::getData() const {
    return data;
}

const std::map<int, int>& Pedido::getItens() const {
    return itens;
}