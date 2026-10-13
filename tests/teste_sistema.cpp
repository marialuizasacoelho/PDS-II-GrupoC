#include "doctest.h"
#include "SistemaDeAutenticacao.hpp"

TEST_CASE("Sistema cadastra um usuario") {
    SistemaDeAutenticacao sistema;

    CHECK(sistema.cadastrarUsuario("ana", "senha123"));
}

TEST_CASE("Sistema autentica usuario com credenciais validas") {
    SistemaDeAutenticacao sistema;

    sistema.cadastrarUsuario("ana", "senha123");

    CHECK(sistema.autenticar("ana", "senha123"));
}

TEST_CASE("Sistema rejeita senha incorreta") {
    SistemaDeAutenticacao sistema;

    sistema.cadastrarUsuario("ana", "senha123");

    CHECK_FALSE(sistema.autenticar("ana", "senhaerrada"));
}

TEST_CASE("Sistema encerra a sessao com logout") {
    SistemaDeAutenticacao sistema;

    sistema.cadastrarUsuario("ana", "senha123");
    sistema.autenticar("ana", "senha123");
    sistema.logout();

    CHECK_FALSE(sistema.estaAutenticado());
}
