#ifndef SISTEMA_DE_AUTENTICACAO_HPP
#define SISTEMA_DE_AUTENTICACAO_HPP

#include <map>
#include <string>

class Usuario;

/**
 * @brief Gerencia o cadastro, a autenticação e as sessões dos usuários.
 */
class SistemaDeAutenticacao {
private:
    // Associa o e-mail ao usuário cadastrado.
    std::map<std::string, Usuario*> usuarios;

    // Guarda o usuário que está atualmente autenticado.
    Usuario* usuarioAutenticado;

public:
    SistemaDeAutenticacao();

    /**
     * @brief Cadastra um usuário no sistema.
     * @return true se o cadastro for realizado com sucesso.
     */
    bool cadastrarUsuario(Usuario* usuario);

    /**
     * @brief Autentica um usuário usando e-mail e senha.
     * @return true se as credenciais forem válidas.
     */
    bool autenticar(const std::string& email,
                    const std::string& senha);

    /**
     * @brief Encerra a sessão atual.
     */
    void logout();

    /**
     * @brief Verifica se existe uma sessão ativa.
     */
    bool estaAutenticado() const;

    /**
     * @brief Retorna o usuário autenticado.
     */
    Usuario* getUsuarioAutenticado() const;

    /**
     * @brief Verifica se o usuário autenticado é administrador.
     */
    bool usuarioEhAdmin() const;
};

#endif