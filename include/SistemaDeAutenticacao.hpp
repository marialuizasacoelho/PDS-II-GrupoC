#ifndef SISTEMA_DE_AUTENTICACAO_HPP
#define SISTEMA_DE_AUTENTICACAO_HPP

#include <map>
#include <string>

/**
 * @file SistemaDeAutenticacao.hpp
 * @brief Definição da classe SistemaDeAutenticacao.
 */

/**
 * @class SistemaDeAutenticacao
 * @brief Gerencia o cadastro, a autenticação e o encerramento de sessões.
 */
class SistemaDeAutenticacao {
private:
    std::map<std::string, std::string> usuarios;
    std::string usuarioAutenticado;

public:
    /**
     * @brief Cadastra um novo usuário.
     * @param usuario Nome do usuário.
     * @param senha Senha do usuário.
     * @return true se o cadastro for realizado com sucesso.
     */
    bool cadastrarUsuario(const std::string& usuario,
                          const std::string& senha);

    /**
     * @brief Realiza a autenticação de um usuário.
     * @param usuario Nome do usuário.
     * @param senha Senha informada.
     * @return true caso as credenciais sejam válidas.
     */
    bool autenticar(const std::string& usuario,
                    const std::string& senha);

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
