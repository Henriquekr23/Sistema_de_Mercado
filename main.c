#include <stdio.h>
#include <string.h>

//structs
typedef struct{
    int codigo;
    char nome[30];
    float preco;
}Produto;

typedef struct{
    Produto produto;
    int quantidade;
}Carrinho;


//functions
void menu(){
    //Gerencia o fluxo do programa e as opções do usuário.
    printf("===============\n=== MERCADO ===\n===============\n\n");
    printf("(1) Cadastrar Produtos;\n(2) Listar Produtos;\n(3) Comprar Produtos;\n(4) Visualizar Carrinho;\n(5) Fechar Pedido;\n(6) Sair do Sistema;\n");
    printf("\nDigite a funcionalidade desejada: ");
}
void cadastrarProdutos(int codigo, char nome[30], float preco){
    int quantidade;
    printf("\nDigite quantos produtos deseja cadastrar: ");
    scanf("%d", &quantidade);
    for (int i = 0; i < quantidade; i++){
        printf("\nDigite o nome do produto %d: ", i+1);
        scanf(" %29[^\n]s", nome);
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo);
        printf("Digite o preco do produto: ");
        scanf("%f", &preco);
    }
    
    //Permite o cadastro de novos produtos.
}
void listarProdutos(Produto p[]){
    int tamanho = sizeof(p);
    for (int i = 0; i < tamanho; i++){
        printf("Nome: %s; Codigo: %d; Preco: %.2f", p->nome[i], p->codigo[i], p->preco[i]);
    }

    //Exibe todos os produtos cadastrados.
    //A listagem de produtos e a visualização do carrinho devem ser realizadas de forma clara, exibindo informações detalhadas.
}
void comprarProduto(){
    //Adiciona produtos ao carrinho.
    //Um produto só pode ser adicionado ao carrinho se já estiver cadastrado no sistema.
    //Produtos que já estão no carrinho devem ter suas quantidades aumentadas ao invés de serem duplicados.

}
void fecharPedido(){
    //Calcula e exibe o valor total da compra e esvazia o carrinho.
    //Ao fechar o pedido, o carrinho deve ser esvaziado, e o sistema deve retornar ao menu principal.

}
void visualizarCarrinho(){
    //Exibe os produtos no carrinho.
    //A listagem de produtos e a visualização do carrinho devem ser realizadas de forma clara, exibindo informações detalhadas.

}
void temNoCarrinho(){
    //Verifica se o produto já está no carrinho.

}
void pegarProdutoPorCodigo(){
    //Retorna um produto a partir do código informado.

}
void infoProduto(Produto prod){
    //Exibe as informações de um produto.

}


//main
int main(){

    int funcionalidade;
    static Produto p[50];
    static Carrinho c[50];
    

    do{
        menu();
        scanf("%d", &funcionalidade);
        switch (funcionalidade){
        case 1:
            cadastrarProdutos(p->codigo, p->nome, p->preco);
            break;
        case 2:
            listarProdutos(p);
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
            printf("Numero Invalido\n");
            funcionalidade = 6;
            break;
        }

    } while (funcionalidade != 6 );

    return 0;
}
