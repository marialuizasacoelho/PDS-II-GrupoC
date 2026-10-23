#include "SistemaDeAutenticacao.hpp"


bool SistemaDeAutenticacao::cadastrarUsuario(
    const std::string& usuario, 
    const std::string& senha) {

    if (usuario.empty() || senha.empty()) {
        return false;
    }

    if (usuarios.find(usuario) != usuarios.end()) {
        return false;
    }

    usuarios[usuario] = senha;
    return true;
}

bool SistemaDeAutenticacao::autenticar(
    const std::string& usuario, const std::string& senha) {

    auto it = usuarios.find(usuario);

    if (it == usuarios.end() || it->second != senha) {
        return false;
    }

    usuarioAutenticado = usuario;
    return true;
}

void SistemaDeAutenticacao::logout() {
    usuarioAutenticado.clear();
}

bool SistemaDeAutenticacao::estaAutenticado() const {
    return !usuarioAutenticado.empty();
}
