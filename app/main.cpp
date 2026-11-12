#include "Produto.hpp"
#include "CatalogoDeProdutos.hpp"
#include "Carrinho.hpp"
#include "Cliente.hpp"
#include "Administrador.hpp"
#include "Pedido.hpp"
#include "SistemaDeAutenticacao.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

static int lerInteiro(const std::string& mensagem) {
    int valor;

    while (true) {
        std::cout << mensagem;

        if (std::cin >> valor) {
            return valor;
        }

        std::cout << "Entrada invalida. Digite um numero.\n";

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
    }
}

static double lerDouble(const std::string& mensagem) {
    double valor;
    std::string entrada;

    while (true) {
        std::cout << mensagem;
        std::cin >> entrada;

        std::replace(entrada.begin(), entrada.end(), ',', '.');

        std::istringstream conversor(entrada);

        if (conversor >> valor &&
            conversor.eof() &&
            valor > 0) {
            return valor;
        }

        std::cout << "Valor invalido. Digite um numero maior que zero.\n";
    }
}

static std::string removerEspacosExtremos(const std::string& texto) {
    const std::string espacos = " \t\n\r";

    std::size_t inicio = texto.find_first_not_of(espacos);

    if (inicio == std::string::npos) {
        return "";
    }

    std::size_t fim = texto.find_last_not_of(espacos);

    return texto.substr(inicio, fim - inicio + 1);
}

// MENU DO ADMINISTRADOR

static void menuAdministrador(
    Administrador& admin,
    CatalogoDeProdutos& catalogo,
    std::vector<Pedido*>& pedidosCriados,
    const std::vector<Cliente*>& clientes
) {
    bool continuar = true;

    while (continuar) {
        std::cout << "\n--- MENU DO ADMINISTRADOR ---\n"
                  << "1 - Listar produtos\n"
                  << "2 - Cadastrar produto\n"
                  << "3 - Editar produto\n"
                  << "4 - Remover produto\n"
                  << "5 - Atualizar estoque\n"
                << "6 - Visualizar pedidos realizados\n"
                << "0 - Sair\n";

        int opcao = lerInteiro("Opcao: ");

        if (opcao == 0) {
            continuar = false;
        }

        else if (opcao == 1) {
            catalogo.listarProdutos();
        }

        else if (opcao == 2) {
            int id = lerInteiro("ID: ");

            std::string nome;
            std::string descricao;

            std::cout << "Nome: ";
            std::cin >> std::ws;
            std::getline(std::cin, nome);

            std::cout << "Descricao: ";
            std::getline(std::cin, descricao);

            double preco = lerDouble("Preco: ");
            int estoque = lerInteiro("Estoque inicial: ");

            try {
                if (catalogo.buscarProduto(id)) {
                    std::cout << "Ja existe um produto com esse ID.\n";
                } else {
                    admin.cadastrarProduto(
                        catalogo,
                        Produto(id, nome, descricao, preco, estoque)
                    );

                    std::cout << "Produto cadastrado.\n";
                }
            }

            catch (const std::exception& e) {
                std::cout << "Erro: " << e.what() << '\n';
            }
        }

        else if (opcao == 3) {
            int id = lerInteiro("ID do produto: ");

            Produto* produto = catalogo.buscarProduto(id);

            if (produto == nullptr) {
                std::cout << "Produto nao encontrado.\n";
                continue;
            }

            std::string nome;
            std::string descricao;

            std::cout << "Novo nome: ";
            std::cin >> std::ws;
            std::getline(std::cin, nome);

            std::cout << "Nova descricao: ";
            std::getline(std::cin, descricao);

            double preco = lerDouble("Novo preco: ");

            if (produto->atualizarDados(nome, descricao, preco)) {
                std::cout << "Produto atualizado.\n";
            } else {
                std::cout << "Dados invalidos.\n";
            }
        }

        else if (opcao == 4) {
            int id = lerInteiro("ID do produto a remover: ");

            if (catalogo.buscarProduto(id)) {
                admin.removerProduto(catalogo, id);
                std::cout << "Produto removido.\n";
            } else {
                std::cout << "Produto nao encontrado.\n";
            }
        }

        else if (opcao == 5) {
            int id = lerInteiro("ID do produto: ");

            Produto* produto = catalogo.buscarProduto(id);

            if (produto == nullptr) {
                std::cout << "Produto nao encontrado.\n";
                continue;
            }

            int quantidade = lerInteiro("Nova quantidade em estoque: ");

            if (quantidade < 0) {
                std::cout << "Estoque nao pode ser negativo.\n";
            } else {
                admin.atualizarEstoqueProduto(produto, quantidade);
                std::cout << "Estoque atualizado.\n";
            }
        }
                else if (opcao == 6) {
            if (pedidosCriados.empty()) {
                std::cout << "Nenhum pedido realizado.\n";
                continue;
            }

            std::cout << "\n===== PEDIDOS REALIZADOS =====\n";

            for (Pedido* pedido : pedidosCriados) {
                std::string nomeCliente = "Cliente nao identificado";

                // Descobre a qual cliente pertence o pedido
                for (Cliente* cliente : clientes) {
                    std::vector<Pedido*> historico =
                        cliente->getHistoricoPedidos();

                    for (Pedido* pedidoCliente : historico) {
                        if (pedidoCliente == pedido) {
                            nomeCliente = cliente->getNome();
                            break;
                        }
                    }

                    if (nomeCliente != "Cliente nao identificado") {
                        break;
                    }
                }

                std::cout << "\nPedido: " << pedido->getId()
                          << "\nCliente: " << nomeCliente
                          << "\nData: " << pedido->getData()
                          << "\nStatus: " << pedido->getStatus()
                          << "\nProdutos:\n";

                for (const auto& item : pedido->getItens()) {
                    Produto* produto =
                        catalogo.buscarProduto(item.first);

                    if (produto != nullptr) {
                        std::cout << "  - " << produto->getNome()
                                  << " | Quantidade: " << item.second
                                  << " | Preco unitario: R$ "
                                  << produto->getPreco() << '\n';
                    } else {
                        std::cout << "  - Produto ID " << item.first
                                  << " (removido do catalogo)"
                                  << " | Quantidade: " << item.second
                                  << '\n';
                    }
                }

                std::cout << "Valor total: R$ "
                          << pedido->getValorTotal() << '\n';

                std::cout << "------------------------------\n";
            }
        }

        else {
            std::cout << "Opcao invalida.\n";
        }
    }
}

// MENU DO CLIENTE

static void menuCliente(
    Cliente& cliente,
    CatalogoDeProdutos& catalogo,
    std::vector<Pedido*>& pedidosCriados
) {
    bool continuar = true;

    Carrinho* carrinho = cliente.getCarrinho();

    while (continuar) {
        std::cout << "\n--- MENU DO CLIENTE ---\n"
                  << "1 - Listar produtos\n"
                  << "2 - Buscar produto pelo nome\n"
                  << "3 - Adicionar produto ao carrinho\n"
                  << "4 - Visualizar carrinho\n"
                  << "5 - Alterar quantidade no carrinho\n"
                  << "6 - Remover produto do carrinho\n"
                  << "7 - Finalizar compra\n"
                  << "8 - Historico de pedidos\n"
                  << "0 - Sair\n";

        int opcao = lerInteiro("Opcao: ");

        if (opcao == 0) {
            continuar = false;
        }

        else if (opcao == 1) {
            catalogo.listarProdutos();
        }

        else if (opcao == 2) {
            std::string termo;

            std::cout << "Nome ou parte do nome: ";
            std::cin >> std::ws;
            std::getline(std::cin, termo);

            std::vector<Produto*> encontrados =
                catalogo.buscarPorNome(termo);

            if (encontrados.empty()) {
                std::cout << "Nenhum produto encontrado.\n";
            } else {
                for (const auto* produto : encontrados) {
                    std::cout << "ID: " << produto->getId()
                              << " | " << produto->getNome()
                              << " | " << produto->getDescricao()
                              << " | R$ " << produto->getPreco()
                              << " | Estoque: "
                              << produto->getQuantidadeEstoque()
                              << '\n';
                }
            }
        }

        else if (opcao == 3) {
            int id = lerInteiro("ID do produto: ");
            int quantidade = lerInteiro("Quantidade: ");

            if (carrinho->adicionarProduto(catalogo, id, quantidade)) {
                std::cout << "Produto adicionado.\n";
            } else {
                std::cout << "Nao foi possivel adicionar. "
                          << "Verifique ID, quantidade e estoque.\n";
            }
        }

        else if (opcao == 4) {
            carrinho->visualizar(catalogo);
        }

        else if (opcao == 5) {
            int id = lerInteiro("ID do produto: ");
            int quantidade = lerInteiro("Nova quantidade: ");

            if (carrinho->alterarQuantidade(catalogo, id, quantidade)) {
                std::cout << "Quantidade alterada.\n";
            } else {
                std::cout << "Nao foi possivel alterar. "
                          << "Verifique produto e estoque.\n";
            }
        }

       else if (opcao == 6) {
    int id = lerInteiro("ID do produto a remover: ");

    auto it = carrinho->getProdutos().find(id);

    if (it == carrinho->getProdutos().end()) {
        std::cout << "Produto nao encontrado no carrinho.\n";
    } else {
        carrinho->removerProduto(id);
        std::cout << "Produto removido do carrinho.\n";
    }
}

        else if (opcao == 7) {
            if (carrinho->getProdutos().empty()) {
                std::cout << "Carrinho vazio.\n";
                continue;
            }

            carrinho->visualizar(catalogo);

            std::cout << "Confirmar compra? (s/n): ";

            char confirmar;
            std::cin >> confirmar;

            if (confirmar == 's' || confirmar == 'S') {
                const std::map<int, int> itens =
                    carrinho->getProdutos();

                bool estoqueOk = true;

                for (const auto& item : itens) {
                    Produto* produto = catalogo.buscarProduto(item.first);

                    if (produto == nullptr ||
                        !produto->possuiEstoqueSuficiente(item.second)) {
                        estoqueOk = false;
                    }
                }

                if (!estoqueOk) {
                    std::cout << "Estoque insuficiente. "
                              << "Compra nao realizada.\n";
                    continue;
                }

                double total = carrinho->calcularTotal(catalogo);

                int idPedido =
                    static_cast<int>(pedidosCriados.size()) + 1;

                Pedido* pedido = new Pedido(idPedido, total, itens);

                pedido->finalizar();

                for (const auto& item : itens) {
                    catalogo.buscarProduto(item.first)
                        ->deduzirEstoque(item.second);
                }

                cliente.adicionarPedidoAoHistorico(pedido);

                pedidosCriados.push_back(pedido);

                carrinho->limpar();

                std::cout << "Compra finalizada!\n"
                          << "Pedido: " << pedido->getId()
                          << " | Data: " << pedido->getData()
                          << " | Total: R$ "
                          << pedido->getValorTotal() << '\n';
            }

            else {
                std::cout << "Compra cancelada. "
                          << "Estoque preservado.\n";
            }
        }

        else if (opcao == 8) {
            std::vector<Pedido*> historico =
                cliente.getHistoricoPedidos();

            if (historico.empty()) {
                std::cout << "Nenhum pedido realizado.\n";
                continue;
            }

            for (const Pedido* pedido : historico) {
                std::cout << "Pedido " << pedido->getId()
                          << " | Data: " << pedido->getData()
                          << " | Total: R$ " << pedido->getValorTotal()
                          << " | Status: " << pedido->getStatus()
                          << '\n';

                for (const auto& item : pedido->getItens()) {
                    Produto* produto = catalogo.buscarProduto(item.first);

                    std::cout << "  Produto ID " << item.first;

                    if (produto) {
                        std::cout << " - " << produto->getNome();
                    }

                    std::cout << " | Quantidade: "
                              << item.second << '\n';
                }
            }
        }

        else {
            std::cout << "Opcao invalida.\n";
        }
    }
}

// PROGRAMA PRINCIPAL

int main() {
    std::cout << std::fixed << std::setprecision(2);

    SistemaDeAutenticacao sistema;

    Administrador admin(
        1,
        "Administrador",
        "admin@loja.com",
        "admin123"
    );

    sistema.cadastrarUsuario(&admin);

    CatalogoDeProdutos catalogo;

    catalogo.adicionarProduto(
        Produto(1, "Notebook", "Notebook 15 polegadas", 3500.00, 5)
    );

    catalogo.adicionarProduto(
        Produto(2, "Mouse", "Mouse sem fio", 80.00, 10)
    );

    catalogo.adicionarProduto(
        Produto(3, "Teclado", "Teclado mecanico", 250.00, 7)
    );

    std::vector<Cliente*> clientes;
    std::vector<Pedido*> pedidosCriados;

    int proximoIdCliente = 2;

    bool sair = false;

    while (!sair) {
        std::cout << "\n================================\n"
                  << "       BEM-VINDA A NOSSA LOJA\n"
                  << "================================\n"
                  << "1 - Cadastrar cliente\n"
                  << "2 - Fazer login\n"
                  << "0 - Sair\n";

        int opcao = lerInteiro("Escolha uma opcao: ");

        if (opcao == 0) {
            sair = true;
        }

        else if (opcao == 1) {
            std::string nome;
            std::string email;
            std::string senha;

           std::cout << "Nome: ";
std::cin >> std::ws;
std::getline(std::cin, nome);

std::cout << "E-mail: ";
std::getline(std::cin, email);

std::cout << "Senha: ";
std::getline(std::cin, senha);

nome = removerEspacosExtremos(nome);
email = removerEspacosExtremos(email);
senha = removerEspacosExtremos(senha);

            if (nome.empty() || email.empty() || senha.empty()) {
                std::cout << "Preencha todos os campos.\n";
                continue;
            }

            Cliente* novo = new Cliente(
                proximoIdCliente,
                nome,
                email,
                senha
            );

            if (sistema.cadastrarUsuario(novo)) {
                clientes.push_back(novo);
                ++proximoIdCliente;

                std::cout << "Cadastro realizado.\n";
            } else {
                delete novo;
                std::cout << "E-mail ja cadastrado.\n";
            }
        }

        else if (opcao == 2) {
            std::string email;
            std::string senha;

          std::cout << "E-mail: ";
std::cin >> std::ws;
std::getline(std::cin, email);

std::cout << "Senha: ";
std::getline(std::cin, senha);

email = removerEspacosExtremos(email);
senha = removerEspacosExtremos(senha);

            if (!sistema.autenticar(email, senha)) {
                std::cout << "E-mail ou senha incorretos.\n";
                continue;
            }

            std::cout << "Login realizado.\n";

            if (sistema.usuarioEhAdmin()) {
                menuAdministrador(
    admin,
    catalogo,
    pedidosCriados,
    clientes
);
            } else {
                Cliente* cliente =
                    static_cast<Cliente*>(
                        sistema.getUsuarioAutenticado()
                    );

                std::cout << "Ola, "
                          << cliente->getNome() << "!\n";

                menuCliente(
                    *cliente,
                    catalogo,
                    pedidosCriados
                );
            }

            sistema.logout();
        }

        else {
            std::cout << "Opcao invalida.\n";
        }
    }

    for (Pedido* pedido : pedidosCriados) {
        delete pedido;
    }

    for (Cliente* cliente : clientes) {
        delete cliente;
    }

    std::cout << "Ate logo!\n";

    return 0;
}