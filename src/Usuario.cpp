#include "Usuario.hpp"

Usuario::Usuario(int id, const std::string& nome,
                 const std::string& email, const std::string& senha)
    : id(id), nome(nome), email(email), senha(senha) {

    if (id <= 0) {
        throw std::invalid_argument("ID do usuario deve ser um numero positivo.");
    }
    if (nome.empty()) {
        throw std::invalid_argument("Nome do usuario nao pode ser vazio.");
    }
    if (email.empty()) {
        throw std::invalid_argument("Email do usuario nao pode ser vazio.");
    }
    if (senha.empty()) {
        throw std::invalid_argument("Senha do usuario nao pode ser vazia.");
    }
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
    if (senhaInput.empty()) {
        throw std::invalid_argument("A senha para validacao nao pode ser vazia.");
    }
    return senhaInput == senha;
}
