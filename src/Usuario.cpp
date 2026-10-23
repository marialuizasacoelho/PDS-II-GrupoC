
#include "Usuario.hpp"

Usuario::Usuario(int id, const std::string& nome,
                 const std::string& email, const std::string& senha)
    : id(id), nome(nome), email(email), senha(senha) {
}

int Usuario::getId() const {
    return id;
}

std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getEmail() const {
    return email;
}

bool Usuario::validarSenha(const std::string& senhaInput) const {
    return senhaInput == senha;
}
