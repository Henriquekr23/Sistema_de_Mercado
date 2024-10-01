#include <stdio.h>
#include <string.h>

#define MAX 50

//structs e declaracoes
typedef struct{
    int codigo;
    char nome[30];
    float preco;
}Produto;

typedef struct{
    Produto produto;
    int quantidade;
}Carrinho;

Produto p[MAX];
Carrinho c[MAX];
int totalProdutos = 0, totalCarrinho = 0;

void menu();
void cadastrarProdutos();
void listarProdutos();
void atualizarInformacoes();
void comprarProduto();
void removerDoCarrinho();
void fecharPedido();
void visualizarCarrinho();
int temNoCarrinho(int codigo);
int pegarProdutoPorCodigo(int codigo);
void infoProduto();

//main
int main(){
    menu();
    return 0;
}

//functions
void menu(){
    //Gerencia o fluxo do programa e as opções do usuário.

    int funcionalidade;
    do{
    printf("\n\n-=============-\n-=| MERCADO |=-\n-=============-\n\n");
    printf("(1) Cadastrar Produtos;\n(2) Listar Produtos;\n(3) Comprar Produtos;\n(4) Visualizar Carrinho;\n(5) Informacoes Produtos;\n(6) Fechar Pedido;\n(0) Sair do Sistema;\n");
    printf("\nDigite a funcionalidade desejada: ");
    scanf("%d", &funcionalidade);
        switch (funcionalidade){
        case 1: 
            cadastrarProdutos();
            break;
        case 2: 
            listarProdutos();
            break;
        case 3: 
            comprarProduto();
            break;
        case 4: 
            visualizarCarrinho();
            break;
        case 5:
            infoProduto();
            break;
        case 6: 
            fecharPedido();
            break;
        case 0:
            break;
        default:
            printf("\nNumero Invalido\n\n");
            break;
        }

    } while (funcionalidade != 0);
}

void cadastrarProdutos(){
    //Permite o cadastro de novos produtos.
    int quantidade; //Variavel auxiliar
    printf("\n-== Cadastro de Produtos ==-\n");
    printf("Digite quantos produtos deseja cadastrar: ");
    scanf("%d", &quantidade);
    quantidade += totalProdutos;
    if (quantidade < MAX+1){
        for (int i = totalProdutos; i < quantidade; i++){
            printf("Nome do produto %d: ", i+1);
            scanf(" %29[^\n]s", p[i].nome);
            printf("Preco do produto %d: ", i+1);
            scanf("%f", &p[i].preco);
            do{
                printf("Codigo do produto %d: ", i+1);
                scanf("%d", &p[i].codigo);
                if (p[i].codigo <= 9){
                    printf("Codigo invalido, deve ser maior que 9\n");
                }
            } while (p[i].codigo < 9);
            totalProdutos++;
            printf("Produto Cadastrado!\n\n");
        }
    } else {
        printf("Quantidade invalida, espaco sobrando para cadastro: %d", 50 - totalProdutos);
        cadastrarProdutos();
    }
}

void listarProdutos(){
    //Exibe todos os produtos cadastrados.
    //A listagem de produtos e a visualização do carrinho devem ser realizadas de forma clara, exibindo informações detalhadas.

    int funcionalidade; // Variavel auxiliar
    if (totalProdutos > 0){
            printf("\n-== Produtos Cadastrados ==-\n");
        for (int i = 0; i < totalProdutos; i++){
            printf("Nome: %s | Preco: %.2f | Codigo: %d\n", p[i].nome, p[i].preco, p[i].codigo);
            }
        printf("\nDigite 1 para voltar ou 2 para atualizar alguma informacao: ");
        scanf("%d", &funcionalidade);
        if (funcionalidade != 2){

        } else {
            atualizarInformacoes();
        }
        
    } else {
        printf("Sem produtos cadastrados!");
    }
}

void atualizarInformacoes(){
    //Funcao para atualizar alguma informacao de um produto cadastrado
    int codigo, opcao;
    printf("\n-== Atualizar Produto ==-\n");
    printf("Digite o codigo do produto que deseja atualizar: ");
    scanf("%d", &codigo);
    printf("Agora, digite o que deseja alterar do produto:\n(1) Nome\n(2) Preco\n(3) Codigo\n");
    scanf("%d", &opcao);
    
}

void comprarProduto(){
    //Adiciona produtos ao carrinho.
    //Um produto só pode ser adicionado ao carrinho se já estiver cadastrado no sistema.
    //Produtos que já estão no carrinho devem ter suas quantidades aumentadas ao invés de serem duplicados.

    int codigo;
    printf("\n-== Comprar Produtos ==-\n");
    printf("Digite o codigo do produto que deseja cadastrar (Digite 1 para voltar ou 2 para listar os produtos): ");
    scanf("%d", &codigo);
    if (codigo == 1){

    } else if (codigo == 2){
        listarProdutos();
        comprarProduto();
    } else {
        int produto = pegarProdutoPorCodigo(codigo); //Variavel p recebe a posicao do produto
        if (produto != -1){ // Se o produto existir
        int verificacao = temNoCarrinho(codigo); // Variavel recebe o valor retornado da funcao temNoCarrinho
            if (verificacao == 1){ // Se o valor for diferente de 1
                c[produto].quantidade++; // Quantidade do produto +1
            } else if (verificacao == -1){ // Se for igual a 1
                if (totalCarrinho < MAX){ // Se o totalCarrinho for menor que 50
                    c[totalCarrinho].produto = p[produto]; // Posicao referente ao totalCarrinho(ultimo valor do vetor) recebe o conteudo do produto
                    c[totalCarrinho].quantidade = 1; // E sua quantidade e 1
                    totalCarrinho++; // Total do carrinho +1
                } else {
                    printf("Carrinho cheio!"); // Se for maior que 50 
                }
            }
            printf("Produto adicionado ao carrinho!\n");
        } else {
            printf("Produto nao encontrado\n");
        }
    }
}

void removerDoCarrinho(){
    //Função destinada a remover item já inserido no carrinho
    int codigo;
    printf("\n-== Remover Produtos ==-\n");
    printf("Digite o codigo do produto que deseja remover (Digite 1 para voltar ao menu ou 2 para listar os produtos): ");
    scanf("%d", &codigo);
    if (codigo == 1){
        
    } else if (codigo == 2){
        listarProdutos();
        removerDoCarrinho();
    } else {
        int produto = pegarProdutoPorCodigo(codigo); // Variavel produto recebe a posicao do codigo
        if (produto != -1){ // Caso o produto exista
            int verificacao = temNoCarrinho(codigo);
            if (verificacao == 1){
                c[produto].quantidade--;
            } else if (verificacao == -1){
                for (int i = produto; i < totalCarrinho; i++){
                    c[i] = c[i+1];
                }
                totalCarrinho--;
            }
        } else {
            printf("Produto nao encontrado\n");
        } 
    } 
    printf("Produto removido!");
}

void fecharPedido(){
    //Calcula e exibe o valor total da compra e esvazia o carrinho.
    //Ao fechar o pedido, o carrinho deve ser esvaziado, e o sistema deve retornar ao menu principal.
    float total = 0, opcao = 0; //Variavel auxiliar
    printf("\n-== Fechamento de Pedido ==-\n");
    for (int i = 0; i < totalCarrinho; i++){
        if (c[i].quantidade != 1){
            total += c[i].quantidade*c[i].produto.preco;
        } else {
            total += c[i].produto.preco;
        }
        printf("Nome: %s | Codigo: %d | Quantidade: %d | Subtotal: %.2f\n", c[i].produto.nome, c[i].produto.codigo, c[i].quantidade , total);
    }
    printf("\nValor total do Carrinho: %.2f\n", total);
    printf("\nDigite 1 para esvaziar o carrinho ou 2 para remover item do carrinho: ");
    scanf("%d", &opcao);
    if (opcao == 1){
        totalCarrinho = 0;
        printf("Carrinho esvaziado!");   
    } else if (opcao == 2){
        removerDoCarrinho();
    }
}

void visualizarCarrinho(){
    //Exibe os produtos no carrinho.
    //A listagem de produtos e a visualização do carrinho devem ser realizadas de forma clara, exibindo informações detalhadas.
    int funcionalidade; //Variavel auxiliar
    printf("\n-== Carrinho ==-\n");
    if (totalCarrinho > 0){
        for (int i = 0; i < totalCarrinho; i++){
            printf("Nome: %s | Preco: %.2f | Codigo: %d | Quantidade: %d\n", c[i].produto.nome, c[i].produto.preco, c[i].produto.codigo, c[i].quantidade);
        }
    } else {
        printf("Carrinho Vazio, digite 1 para voltar: ");
        scanf("%d", &funcionalidade);
        menu();
    }
    printf("\nDigite 1 para voltar ou 2 para remover item do Carrinho: ");
    scanf("%d", &funcionalidade);
    if (funcionalidade != 2){
        
    } else {
        removerDoCarrinho();
    }
}

int temNoCarrinho(int codigo){
    //Verifica se o produto já está no carrinho.
    for (int i = 0; i < totalCarrinho; i++){
        if (c[i].produto.codigo == codigo){
            return 1;
        }
    }
    return -1;
}

int pegarProdutoPorCodigo(int codigo){
    //Retorna um produto a partir do código informado.
    for (int i = 0; i < totalProdutos; i++){
        if (p[i].codigo == codigo){
            return i; //Retorna a posicao do produto
        }
    }
    return -1; // Se o produto nao for encontrado retorna -1
}

void infoProduto(){
    //Exibe as informações de um produto.
    int codigo, posicao = -1; //Variavel auxiliar
    printf("\n-== Informacoes de um Produto ==-\n");
    printf("Digite o codigo do produto que deseja obter as informacoes: ");
    scanf("%d", &codigo);
    posicao = pegarProdutoPorCodigo(codigo);
    if (posicao != -1){
        printf("Nome: %s | Preco: %.2f | Codigo: %d", p[posicao].nome, p[posicao].preco, codigo);
    } else {
        printf("Produto nao encontrado.");
    }
    
}
