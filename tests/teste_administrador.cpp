#include "doctest.h"
#include "Administrador.hpp"
#include "Produto.hpp"

TEST_CASE("Administrador armazena seus dados de usuario") {
    Administrador admin(1, "Carlos", "carlos@example.com", "senha123");

    CHECK(admin.getId() == 1);
    CHECK(admin.getNome() == "Carlos");
    CHECK(admin.getEmail() == "carlos@example.com");
}

TEST_CASE("Administrador possui privilegios administrativos") {
    Administrador admin(1, "Carlos", "carlos@example.com", "senha123");

    CHECK(admin.ehAdmin());
}

TEST_CASE("Administrador pode atualizar estoque de um produto") {
    Administrador admin(1, "Carlos", "carlos@example.com", "senha123");
    Produto produto(10, "Teclado", "Teclado USB", 100.0, 5);

    admin.atualizarEstoqueProduto(&produto, 12);

    CHECK(produto.getQuantidadeEstoque() == 12);
}
