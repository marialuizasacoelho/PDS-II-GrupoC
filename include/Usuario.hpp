#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <stdexcept>

/**
 * @file Usuario.hpp
 * @brief Definição da classe base Usuario com tratamento de exceções.
 */

/**
 * @class Usuario
 * @brief Classe abstrata que representa um usuário no sistema de e-commerce.
 */
class Usuario {
protected:
    int id;
    std::string nome;
    std::string email;
    std::string senha;

public:
    /**
     * @brief Construtor da classe Usuario.
     * @param id Identificador único do usuário.
     * @param nome Nome do usuário.
     * @param email E-mail de acesso.
     * @param senha Senha de acesso.
     * @throws std::invalid_argument Se o ID for <= 0 ou se algum campo de texto for vazio.
     */
    Usuario(int id, const std::string& nome, const std::string& email, const std::string& senha);

    /**
     * @brief Destrutor virtual para garantia da hierarquia de herança.
     */
    virtual ~Usuario() = default;

    /**
     * @brief Obtém o ID do usuário.
     * @return ID numérico.
     */
    int getId() const;

    /**
     * @brief Obtém o nome do usuário.
     * @return Nome em texto.
     */
    std::string getNome() const;

    /**
     * @brief Obtém o e-mail do usuário.
     * @return E-mail em texto.
     */
    std::string getEmail() const;

    /**
     * @brief Valida se a senha informada corresponde à cadastrada.
     * @param senhaInput Senha a ser testada.
     * @return true se correta, false caso contrário.
     * @throws std::invalid_argument Se a senha fornecida for vazia.
     */
    bool validarSenha(const std::string& senhaInput) const;

    /**
     * @brief Verifica se o usuário possui permissão de administrador.
     * @return true se for admin, false caso contrário.
     */
    virtual bool ehAdmin() const = 0;
};

#endif // USUARIO_HPP
