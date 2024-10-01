# Sistema_de_Mercado

Esse código implementa um sistema de gestão de produtos e carrinho de compras para um mercado, utilizando a linguagem C. Ele permite que o usuário cadastre, liste, compre, visualize e remova produtos do carrinho, além de fechar pedidos. Vou explicar cada parte do código e suas funcionalidades.

*Estruturas e Variáveis Globais*
Produto: Uma estrutura que armazena informações de cada produto, como o código, nome e preço.
Carrinho: Estrutura que relaciona um produto com sua quantidade no carrinho.
p[MAX] e c[MAX]: Arrays para armazenar até 50 produtos e itens no carrinho.
totalProdutos e totalCarrinho: Variáveis que controlam a quantidade de produtos cadastrados e a quantidade de itens no carrinho, respectivamente.

# Funções:

1. main
Função principal que chama o menu. Serve como ponto de entrada para o programa.

2. menu
Responsabilidade: Gerencia o fluxo do programa, exibindo opções como cadastrar produtos, listar produtos, comprar produtos, visualizar o carrinho, etc.
Explicação: O usuário seleciona uma funcionalidade e o programa chama a função correspondente, utilizando um loop do-while até que a opção de sair (0) seja escolhida.

3. cadastrarProdutos
Responsabilidade: Cadastra novos produtos no sistema.
Explicação: O usuário define a quantidade de produtos a serem cadastrados, preenche as informações de nome, preço e código. O código do produto deve ser maior que 9 para evitar conflitos. Essa função aumenta o valor de totalProdutos conforme novos produtos são cadastrados.

4. listarProdutos
Responsabilidade: Exibe todos os produtos cadastrados.
Explicação: A função imprime a lista de produtos com detalhes (nome, preço, código). Após listar, dá ao usuário a opção de voltar ao menu ou atualizar algum produto.

5. atualizarInformacoes
Responsabilidade: Permite a atualização de nome, preço ou código de um produto.
Explicação: O usuário insere o código do produto que deseja modificar e escolhe o que quer alterar (nome, preço ou código). O programa valida a existência do produto antes de fazer qualquer modificação.

6. comprarProduto
Responsabilidade: Adiciona um produto ao carrinho.
Explicação: O usuário fornece o código do produto que deseja comprar. Se o produto já estiver no carrinho, a quantidade é aumentada. Caso contrário, o produto é adicionado ao carrinho pela primeira vez.

7. removerDoCarrinho
Responsabilidade: Remove um produto do carrinho.
Explicação: O usuário pode remover um produto do carrinho reduzindo sua quantidade ou eliminando-o completamente. A função ajusta o carrinho conforme necessário.

8. fecharPedido
Responsabilidade: Finaliza a compra, exibindo o total e esvaziando o carrinho.
Explicação: A função calcula o valor total do carrinho e dá a opção de esvaziá-lo ou remover itens antes de fechar o pedido.

9. visualizarCarrinho
Responsabilidade: Exibe os produtos no carrinho.
Explicação: Mostra os itens do carrinho com detalhes (nome, preço, código, quantidade). Caso o carrinho esteja vazio, o usuário é informado.

10. temNoCarrinho
Responsabilidade: Verifica se um produto já está no carrinho.
Explicação: A função percorre o carrinho para verificar se o código do produto já foi adicionado.

11. pegarProdutoPorCodigo
Responsabilidade: Localiza um produto a partir de seu código.
Explicação: Percorre o array de produtos cadastrados e retorna a posição no array, ou -1 se não encontrar o produto.

12. infoProduto
Responsabilidade: Exibe informações de um produto específico com base no código fornecido.
Explicação: O usuário insere o código e recebe as informações detalhadas do produto, como nome e preço.

*Resumo Geral*
Este sistema simula um ambiente de compras, onde o usuário pode adicionar, remover e listar produtos, além de manipular o carrinho de compras. Cada função tem uma responsabilidade clara, garantindo a modularidade do código. A interação ocorre através de um menu de opções que gerencia o fluxo do programa.
