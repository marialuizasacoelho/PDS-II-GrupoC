#include "SistemaDeAutenticacao.hpp"
#include "Usuario.hpp"

SistemaDeAutenticacao::SistemaDeAutenticacao()
    : usuarioAutenticado(nullptr) {
}

bool SistemaDeAutenticacao::cadastrarUsuario(Usuario* usuario) {
    if (usuario == nullptr) {
        return false;
    }

    if (usuario->getNome().empty() || usuario->getEmail().empty()) {
        return false;
    }

    if (usuarios.find(usuario->getEmail()) != usuarios.end()) {
        return false;
    }

    usuarios[usuario->getEmail()] = usuario;

    return true;
}

bool SistemaDeAutenticacao::autenticar(
    const std::string& email,
    const std::string& senha) {

    auto it = usuarios.find(email);

    if (it == usuarios.end()) {
        return false;
    }

    if (!it->second->validarSenha(senha)) {
        return false;
    }

    usuarioAutenticado = it->second;

    return true;
}

void SistemaDeAutenticacao::logout() {
    usuarioAutenticado = nullptr;
}

bool SistemaDeAutenticacao::estaAutenticado() const {
    return usuarioAutenticado != nullptr;
}

Usuario* SistemaDeAutenticacao::getUsuarioAutenticado() const {
    return usuarioAutenticado;
}

bool SistemaDeAutenticacao::usuarioEhAdmin() const {
    if (usuarioAutenticado == nullptr) {
        return false;
    }

    return usuarioAutenticado->ehAdmin();
}