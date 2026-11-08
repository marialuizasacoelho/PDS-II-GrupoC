#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto {
private:
    int id;
    std::string nome;
    std::string descricao;
    double preco;
    int quantidadeEstoque;

public:
    Produto(int id, const std::string& nome, const std::string& descricao,
            double preco, int estoque);

    int getId() const;
    std::string getNome() const;
    std::string getDescricao() const;
    double getPreco() const;
    int getQuantidadeEstoque() const;

    bool estaDisponivel() const;
    bool possuiEstoqueSuficiente(int qtd) const;
    void deduzirEstoque(int qtd);
    void setQuantidadeEstoque(int novaQtd);

    bool atualizarDados(const std::string& novoNome,
                        const std::string& novaDescricao,
                        double novoPreco);
};

#endif