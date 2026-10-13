#include "doctest.h"
#include "Usuario.hpp"
#include "Cliente.hpp"
#include "Administrador.hpp"

TEST_CASE("Usuario disponibiliza os dados herdados") {
    Cliente cliente(1, "Ana", "ana@example.com", "senha123");

    CHECK(cliente.getId() == 1);
    CHECK(cliente.getNome() == "Ana");
    CHECK(cliente.getEmail() == "ana@example.com");
}

TEST_CASE("Usuario valida a senha informada") {
    Cliente cliente(1, "Ana", "ana@example.com", "senha123");

    CHECK(cliente.validarSenha("senha123"));
    CHECK_FALSE(cliente.validarSenha("senhaerrada"));
}

TEST_CASE("Cliente e administrador possuem permissoes diferentes") {
    Cliente cliente(1, "Ana", "ana@example.com", "senha123");
    Administrador admin(2, "Carlos", "carlos@example.com", "senha456");

    CHECK_FALSE(cliente.ehAdmin());
    CHECK(admin.ehAdmin());
}
