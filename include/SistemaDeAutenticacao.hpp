#ifndef SISTEMA_DE_AUTENTICACAO_HPP
#define SISTEMA_DE_AUTENTICACAO_HPP

#include <string>

class SistemaDeAutenticacao {
public:
    /**
     * @brief Cadastra novo usuário.
     * @param usuario Nome do usuário.
     * @param senha Senha do usuário.
     * @return true se o cadastro for realizado com sucesso.
     */
    bool cadastrarUsuario(const std::string& usuario, const std::string& senha);

    /**
     * @brief Realiza a autenticação de um usuário.
     * @param usuario Nome do usuário.
     * @param senha Senha informada.
     * @return true caso as credenciais sejam válidas.
     */
    bool autenticar(const std::string& usuario, const std::string& senha);

    /**
     * @brief Encerra a sessão do usuário.
     */
    void logout();

    /**
     * @brief Verifica se existe um usuário autenticado.
     * @return true caso exista uma sessão ativa.
     */
    bool estaAutenticado() const;
};

#endif