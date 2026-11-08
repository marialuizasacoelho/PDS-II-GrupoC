#include "doctest.h"
#include "SistemaDeAutenticacao.hpp"
#include "Cliente.hpp"
#include "Administrador.hpp"

TEST_CASE("Sistema cadastra um usuario") {
    SistemaDeAutenticacao sistema;
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    CHECK(sistema.cadastrarUsuario(&cliente));
}

TEST_CASE("Sistema impede cadastro de email duplicado") {
    SistemaDeAutenticacao sistema;

    Cliente cliente1(1, "Ana", "ana@email.com", "senha123");
    Cliente cliente2(2, "Maria", "ana@email.com", "outrasenha");

    CHECK(sistema.cadastrarUsuario(&cliente1));
    CHECK_FALSE(sistema.cadastrarUsuario(&cliente2));
}

TEST_CASE("Sistema autentica usuario com credenciais validas") {
    SistemaDeAutenticacao sistema;
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    sistema.cadastrarUsuario(&cliente);

    CHECK(sistema.autenticar("ana@email.com", "senha123"));
    CHECK(sistema.estaAutenticado());
}

TEST_CASE("Sistema rejeita senha incorreta") {
    SistemaDeAutenticacao sistema;
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    sistema.cadastrarUsuario(&cliente);

    CHECK_FALSE(sistema.autenticar("ana@email.com", "senhaerrada"));
    CHECK_FALSE(sistema.estaAutenticado());
}

TEST_CASE("Sistema rejeita email inexistente") {
    SistemaDeAutenticacao sistema;

    CHECK_FALSE(sistema.autenticar("inexistente@email.com", "senha123"));
}

TEST_CASE("Sistema encerra a sessao com logout") {
    SistemaDeAutenticacao sistema;
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    sistema.cadastrarUsuario(&cliente);
    sistema.autenticar("ana@email.com", "senha123");
    sistema.logout();

    CHECK_FALSE(sistema.estaAutenticado());
    CHECK(sistema.getUsuarioAutenticado() == nullptr);
}

TEST_CASE("Sistema identifica administrador autenticado") {
    SistemaDeAutenticacao sistema;
    Administrador admin(1, "Admin", "admin@email.com", "admin123");

    sistema.cadastrarUsuario(&admin);

    CHECK(sistema.autenticar("admin@email.com", "admin123"));
    CHECK(sistema.usuarioEhAdmin());
}

TEST_CASE("Sistema identifica cliente como nao administrador") {
    SistemaDeAutenticacao sistema;
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    sistema.cadastrarUsuario(&cliente);
    sistema.autenticar("ana@email.com", "senha123");

    CHECK_FALSE(sistema.usuarioEhAdmin());
}

TEST_CASE("Sistema nao considera usuario nao autenticado como administrador") {
    SistemaDeAutenticacao sistema;

    CHECK_FALSE(sistema.usuarioEhAdmin());
}