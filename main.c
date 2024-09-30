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
void comprarProduto();
void fecharPedido();
void visualizarCarrinho();
int temNoCarrinho(int codigo);
Produto *pegarProdutoPorCodigo(int codigo);
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
    printf("\n-==============\n-=| MERCADO |=-\n-=============-\n\n");
    printf("(1) Cadastrar Produtos;\n(2) Listar Produtos;\n(3) Comprar Produtos;\n(4) Visualizar Carrinho;\n(5) Fechar Pedido;\n(6) Sair do Sistema;\n");
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
            fecharPedido();
            break;
        case 6:
            break;
        default:
            printf("\nNumero Invalido\n\n");
            break;
        }

    } while (funcionalidade != 6 );
}
void cadastrarProdutos(){
    //Permite o cadastro de novos produtos.

    int quantidade; //Variavel auxiliar
    printf("\n-== Cadastro de Produtos ==-\n");
    printf("Digite quantos produtos deseja cadastrar: ");
    scanf("%d", &quantidade);
    if (quantidade + totalProdutos < MAX){
        for (int i = 0; i < quantidade; i++){
            printf("Nome do produto %d: ", i+1);
            scanf(" %29[^\n]s", p[i].nome);
            printf("Preco do produto %d: ", i+1);
            scanf("%f", &p[i].preco);
            printf("Codigo do produto %d: ", i+1);
            scanf("%d", &p[i].codigo);
            p[totalProdutos++];
        }
    } else {
        printf("Quantidade invalida, espaco sobrando para cadastro: %d\n", 50 - totalProdutos);
    }
}
void listarProdutos(){
    //Exibe todos os produtos cadastrados.
    //A listagem de produtos e a visualização do carrinho devem ser realizadas de forma clara, exibindo informações detalhadas.

    int sair; //Variavel auxiliar
    printf("\n-== Produtos Cadastrados ==-\n");
    for (int i = 0; i < totalProdutos; i++){
        printf("Nome: %s | Preco: %.2f | Codigo: %d\n", p[i].nome, p[i].preco, p[i].codigo);
    }
}
void comprarProduto(){
    //Adiciona produtos ao carrinho.
    //Um produto só pode ser adicionado ao carrinho se já estiver cadastrado no sistema.
    //Produtos que já estão no carrinho devem ter suas quantidades aumentadas ao invés de serem duplicados.

    int codigo, condicao;
    printf("\n-== Comprar Produtos ==-\n");
    printf("Digite o codigo do produto que deseja cadastrar (Caso nao saiba, digite 0 para listar os produtos): ");
    scanf("%d", &codigo);
    if (codigo == 0){
        listarProdutos();
        comprarProduto();
    }else{
        Produto *p = pegarProdutoPorCodigo(codigo);
        if (p != NULL){
        condicao = temNoCarrinho(codigo);
            if (condicao != -1){
                c[condicao].quantidade++;
            } else {
                if (totalCarrinho < MAX){
                    c[totalCarrinho].produto = *p;
                    c[totalCarrinho].quantidade = 1;
                    totalCarrinho++;
                } else {
                    printf("Carrinho cheio!");
                }
            }
            printf("Produto adicionado ao carrinho\n");
        } else {
            printf("Produto nao encontrado\n");
        }
    }
    
}
void fecharPedido(){
    //Calcula e exibe o valor total da compra e esvazia o carrinho.
    //Ao fechar o pedido, o carrinho deve ser esvaziado, e o sistema deve retornar ao menu principal.

}
void visualizarCarrinho(){
    //Exibe os produtos no carrinho.
    //A listagem de produtos e a visualização do carrinho devem ser realizadas de forma clara, exibindo informações detalhadas.
    int funcionalidade; //Variavel auxiliar
    printf("\n-== Carrinho ==-\n");
    for (int i = 0; i < totalCarrinho; i++){
        printf("Nome: %s | Preco: %.2f | Codigo: %d\n", c[i].produto.nome, c[i].produto.preco, c[i].produto.codigo);
    }
    printf("\n(1) Menu\n(2) Fechar Pedido\nDigite a funcionalidade desejada: ");
    scanf("%d", &funcionalidade);
    switch (funcionalidade){
    case 1:
        break;
    case 2:
        fecharPedido();
        break;
    default:
        printf("Numero invalido");
        break;
    }
}
int temNoCarrinho(int codigo){
    //Verifica se o produto já está no carrinho.
    for (int i = 0; i < totalCarrinho; i++){
        if (c[i].produto.codigo == codigo){
            return i;
        }
    }
    return -1;
}
Produto *pegarProdutoPorCodigo(int codigo){
    //Retorna um produto a partir do código informado.
    for (int i = 0; i < totalProdutos; i++){
        return &p[i];
    }
    return NULL;
}
void infoProduto(){
    //Exibe as informações de um produto.
    int codigo, posicao; //Variavel auxiliar
    printf("Digite o codigo do produto que deseja obter as informacoes: ");
    scanf("%d", &codigo);

    printf("Nome: %s | Preco: %.2f | Codigo: %d", p[posicao].nome, p[posicao].preco, codigo);
}
