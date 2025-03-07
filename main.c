#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structs e declaracoes
//Produtos
typedef struct Produto{
    int codigo;
    char nome[30];
    float preco;
}Produto;

typedef struct NodeProduto{
    Produto produto;
    struct NodeProduto *next;
} NodeProduto;

//Carrinho
typedef struct Carrinho{
    Produto produto;
    int quantidade;
}Carrinho;

typedef struct NodeCarrinho{
    Carrinho carrinho;
    struct NodeCarrinho *next;
} NodeCarrinho;

// Declarações das funções
NodeProduto *criarNodeProduto();
NodeCarrinho *criarNodeCarrinho();
void cadastrarProdutos(NodeProduto *P);
void listarProdutos(NodeProduto *P);
Produto *pegarProdutoPorCodigo(int codigo, NodeProduto *P);
void adicionarCarrinho(NodeProduto *P, NodeCarrinho *C);
Carrinho *temNoCarrinho(int codigo, NodeCarrinho *C);
void listarCarrinho(NodeCarrinho *C);
void fecharCarrinho(NodeCarrinho *C);
void menu(NodeCarrinho *C, NodeProduto *P);

//PRODUTOS

//Criando um novo node para os produtos
NodeProduto *criarNodeProduto(){

    NodeProduto *newNode = malloc(sizeof(struct NodeProduto));
    newNode->next = NULL;
    return newNode;
}

//Cadastrando produtos e adicionando na lista
void cadastrarProdutos(NodeProduto *P){

    int quantidade;
    printf("\n-== Cadastro de Produtos ==-\n");
    printf("Digite quantos produtos deseja cadastrar: ");
    scanf("%d", &quantidade);
        for (int i = 0; i < quantidade; i++){
            NodeProduto *newNode = criarNodeProduto();
            printf("Nome do produto %d: ", i+1);
            scanf(" %29[^\n]s", &newNode->produto.nome);
            printf("Preco do produto %d: ", i+1);
            scanf("%f", &newNode->produto.preco);
                do {
                    printf("Codigo do produto %d: ", i+1);
                    scanf("%d", &newNode->produto.codigo);
                    if (newNode->produto.codigo <= 0){
                        printf("Codigo Invalido, por favor reescreva");
                    }
                } while (newNode->produto.codigo <= 0);

            while (P->next != NULL){
                P = P->next;
            }
            P->next = newNode;
        }
}

//Listando todos os produtos na lista
void listarProdutos(NodeProduto *P){

    int colocacao = 1;
    P = P->next;
    printf("\n-== Produtos Cadastrados ==-\n");
    while (P != NULL){
        printf("%d. Nome: %s | Preco: %.2f | Codigo: %d\n", colocacao++, P->produto.nome, P->produto.preco, P->produto.codigo);
        P = P->next;
    }
}

//Retorna um produto a partir do código informado.
Produto *pegarProdutoPorCodigo(int codigo, NodeProduto *P){

    P = P->next;
    while (P != NULL){
        if (P->produto.codigo == codigo){
            return &P->produto;
        }
        P = P->next;
    }
    return NULL;
}

//Exibe as informações de um produto.
void infoProduto(NodeProduto *P){

    int codigo;
    printf("\n-== Informacoes de um Produto ==-\n");
    printf("Digite o codigo do produto que deseja obter as informacoes: ");
    scanf("%d", &codigo);
    Produto *busca = pegarProdutoPorCodigo(codigo, P);
    if (busca != NULL) {
        printf("Nome: %s | Preco: %.2f | Codigo: %d", busca->nome, busca->preco, busca->codigo);
    } else {
        printf("Produto nao encontrado, tente novamente.");
    }
    
}

void removerProduto(NodeProduto *P){
    
    int codigo;
    printf("\n-== Remover Produto ==-\n");
    printf("Digite o codigo do produto que deseja remover");
    scanf("%d", &codigo);
    Produto *busca = pegarProdutoPorCodigo(codigo, P);
    if (busca != NULL) {
        Produto *temp;
        
    } else {
        printf("Produto nao encontrado, tente novamente.");
    }

}

//CARRINHO

//Criando um novo node para os produtos no carrinho
NodeCarrinho *criarNodeCarrinho(){

    NodeCarrinho *newNode = malloc(sizeof(NodeCarrinho));
    newNode->next = NULL;
    return newNode;
}

//Verifica se o produto esta no carrinho
Carrinho *temNoCarrinho(int codigo, NodeCarrinho *C){

    C = C->next;
    while (C != NULL){
        if (C->carrinho.produto.codigo == codigo){
            return &C->carrinho;
        }
        C = C->next;
    }
    return NULL;
}

//Adiciona produtos ao carrinho.
void adicionarCarrinho(NodeProduto *P, NodeCarrinho *C){

    int codigo;
    printf("\n-== Adicionar Produtos ao Carrinho ==-\n");
    printf("Digite o codigo do produto que deseja cadastrar (Digite 0 para listar os produtos): ");
    scanf("%d", &codigo);
    if (codigo == 0){
        listarProdutos(P);
        adicionarCarrinho(P, C);
    } else {
        Produto *verificarProduto = pegarProdutoPorCodigo(codigo, P);
        if (verificarProduto != NULL){ //Se o produto for cadastrado
            Carrinho *verificarCarrinho = temNoCarrinho(codigo, C);
            if (verificarCarrinho != NULL){ //Se o produto estiver no carrinho
                verificarCarrinho->quantidade++;
            } else {
                NodeCarrinho *newNode = criarNodeCarrinho();
                newNode->carrinho.produto = *verificarProduto;
                newNode->carrinho.quantidade = 1;
                while (C->next != NULL){
                    C = C->next;
                }
                C->next = newNode;
            }
            printf("Produto adicionado ao carrinho\n");
        } else { //Se não existir
            printf("Produto nao encontrado, tente novamente.\n");
            adicionarCarrinho(P, C);
        }
    }
}

//Fecha o carrinho
void fecharCarrinho(NodeCarrinho *C){

    float total = 0; int opcao;
    printf("\n-== Fechamento do Carrinho ==-\n");
    if (C->next != NULL){
        C = C->next;
        while (C != NULL){
            if (C->carrinho.quantidade != 1){
                total += C->carrinho.quantidade*C->carrinho.produto.preco;
            } else {
                total += C->carrinho.produto.preco;
            }
            printf("Nome: %s | Preco: %.2f | Quantidade: %d | Subtotal: %.2f\n", C->carrinho.produto.nome, C->carrinho.produto.preco, C->carrinho.quantidade, total);
            C = C->next;
        }
        printf("\nValor total do Carrinho: %.2f\n", total);
        printf("Digite 1 para esvaziar o carrinho: ");
        scanf("%d", &opcao);
    } else {
        printf("Carrinho vazio!");
    }
}

void listarCarrinho(NodeCarrinho *C){

    C = C->next;
    printf("\n-== Carrinho ==-\n");
    if (C == NULL){
        printf("Carrinho Vazio!");
    } else {
        while (C != NULL){
            printf("Nome: %s | Preco: %.2f | Codigo: %d | Quantidade: %d\n", C->carrinho.produto.nome, C->carrinho.produto.preco, C->carrinho.produto.codigo, C->carrinho.quantidade);
            C = C->next;
        }
    }
}

void destruirCarrinho(NodeCarrinho *C){

    NodeCarrinho *temp;
    while (C != NULL){
        temp = C->next;
        free(C);
        C = temp;   
    }
    C = NULL;
    printf("Carrinho esvaziado!");
}

//Função principal do menu
void menu(NodeCarrinho *C, NodeProduto *P){

    int funcionalidade;
    do{
    printf("\n\n-=============-\n-=| MERCADO |=-\n-=============-\n\n");
    printf("(1) Cadastrar Produtos;\n(2) Listar Produtos;\n(3) Comprar Produtos;\n(4) Visualizar Carrinho;\n(5) Informacoes Produtos;\n(6) Fechar Pedido;\n(7) Sair do Sistema;\n");
    printf("\nDigite a funcionalidade desejada: ");
    scanf("%d", &funcionalidade);
        switch (funcionalidade){
        case 1: 
            cadastrarProdutos(P);
            break;
        case 2: 
            listarProdutos(P);
            break;
        case 3: 
            adicionarCarrinho(P, C);
            break;
        case 4: 
            listarCarrinho(C);
            break;
        case 5:
            infoProduto(P);
            break;
        case 6: 
            fecharCarrinho(C);
            destruirCarrinho(C);
            break;
        case 7:
            printf("\nFechando o Sistema...");
            break;
        default:
            printf("\nNumero Invalido\n\n");
            break;
        }

    } while (funcionalidade != 7 );
}

//MAIN

//Execução do Sistema
int main(){

//Criação das listas encadeadas
    NodeCarrinho *C = criarNodeCarrinho();
    NodeProduto *P = criarNodeProduto();

    menu(C, P);

    return 0;
}
