# User Stories — E-commerce

## Cadastro de usuário
### Descrição

Como cliente, quero criar uma conta na plataforma, para poder realizar compras e acompanhar meus pedidos.

### Critérios de aceitação

- Permitir o cadastro de um novo usuário.
- Solicitar nome, e-mail e senha.
- Validar o preenchimento dos campos obrigatórios.
- Impedir o cadastro de e-mails já utilizados.
- Informar ao usuário se o cadastro foi realizado com sucesso.



## Autenticação de usuário
### Descrição

Como cliente, quero realizar login na plataforma, para acessar minha conta e utilizar as funcionalidades personalizadas.

### Critérios de aceitação

- Permitir o login utilizando e-mail e senha.
- Validar as credenciais informadas.
- Impedir o acesso quando as credenciais forem inválidas.
- Informar ao usuário quando houver erro na autenticação.
- Permitir o encerramento da sessão.



## Consulta e busca de produtos
### Descrição

Como cliente, quero visualizar e buscar produtos disponíveis, para encontrar os itens que desejo comprar.

### Critérios de aceitação

- Exibir uma lista de produtos cadastrados.
- Permitir a busca de produtos pelo nome.
- Exibir informações detalhadas de um produto.
- Mostrar nome, descrição, preço e disponibilidade do produto.
- Informar quando nenhum produto corresponder à busca.



## Gerenciamento de produtos
### Descrição

Como administrador, quero cadastrar, editar e remover produtos, para manter o catálogo da plataforma atualizado.

### Critérios de aceitação

- Permitir o cadastro de novos produtos.
- Permitir a alteração das informações de produtos existentes.
- Permitir a remoção de produtos do catálogo.
- Validar o preenchimento das informações obrigatórias.
- Restringir as funcionalidades administrativas aos administradores.



## Gerenciamento de estoque
### Descrição

Como administrador, quero controlar a quantidade disponível de cada produto, para evitar vendas de itens sem estoque.

### Critérios de aceitação

- Armazenar a quantidade disponível de cada produto.
- Permitir a atualização da quantidade em estoque.
- Impedir a compra de produtos sem estoque.
- Atualizar o estoque após a confirmação de uma compra.
- Informar quando a quantidade solicitada for superior ao estoque disponível.



## Gerenciamento do carrinho
### Descrição

Como cliente, quero adicionar, remover e alterar a quantidade de produtos no carrinho, para montar meu pedido antes de finalizar a compra.

### Critérios de aceitação

- Permitir a adição de produtos disponíveis ao carrinho.
- Permitir a remoção de produtos do carrinho.
- Permitir a alteração da quantidade de produtos.
- Calcular o valor total do carrinho.
- Impedir que a quantidade solicitada ultrapasse o estoque disponível.



## Finalização da compra
### Descrição

Como cliente, quero finalizar meu carrinho e realizar um pedido, para concluir a compra dos produtos selecionados.

### Critérios de aceitação

- Permitir a finalização de carrinhos que contenham produtos.
- Exibir um resumo dos produtos e do valor total antes da confirmação.
- Solicitar os dados necessários para concluir o pedido.
- Registrar o pedido após a confirmação da compra.
- Informar ao cliente se o pedido foi criado com sucesso.



## Consulta do histórico de pedidos
### Descrição

Como cliente, quero consultar meu histórico de pedidos, para acompanhar minhas compras realizadas anteriormente.

### Critérios de aceitação

- Permitir a visualização dos pedidos associados à conta do cliente.
- Exibir a data e o valor total de cada pedido.
- Permitir a visualização dos produtos de um pedido específico.
- Exibir o status atual do pedido.
- Impedir o acesso aos pedidos de outros usuários.