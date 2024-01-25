#include <stdio.h>
#include <stdlib.h>
struct Dados{
    char *desc;
    int categoria;
    int dia;
    int mes;
    int ano;

};

void cadastrar(){
    int escolhacadastro=1;
    
    while (escolhacadastro != 0){
        printf("0- Sair\n 1- Adicionar transacao\n");
        scanf("%d",&escolhacadastro);
        if (escolhacadastro == 1){

        }
        else if (escolhacadastro == 0){

        }
        else{
            printf("numero invalido!\n");
        }
    }
    

}
void relatorio(){ // esse não tem opção, simplesmente cria a .txt com as info. dos ultimos 12 meses

}
void relacao(){
    int escolharelacao = 1;
    while (escolharelacao != 0){
        printf("0- Sair\n1- Categoria1\n2- Categoria2\n3- Categoria3\n"); //escolha de categoria
        scanf("%d",&escolhacadastro);
        if (escolharelacao == 1){

        }
        else if (escolharelacao == 2){

        }
        else if (escolharelacao == 3){
            
        }
        else if (escolharelacao == 0){

        }
        else{
            printf("numero invalido!\n");
        }
    }

}
void placeholder1(){

}
void placeholder2(){

}
// principal ------------------------------- principal -------------------------------- principal -------------------------------- principal ---------------------------------
int main(){
    int escolha = 1;
    while (escolha !=0){
        printf("0- Sair\n1- Cadastro\n2-Relatorio dos ultimos 12 meses\n3-Relacao do ultimo mes\n4-???\n5-???: "); //menu interativo
        scanf("%d",&escolha);
        if (escolha ==1){
            printf("Cadastro\n");
            cadastrar();

        }
        else if (escolha ==2){
            printf("Relatorio\n");
            relatorio();

        }
        else if (escolha ==3){
            printf("Relacao\n");
            relacao();

        }
        else if (escolha ==4){
            printf("Placeholder1\n");
            placeholder1();

        }
        else if (escolha ==5){
            printf("Placeholder2\n");
            placeholder2();

        }
        else if (escolha ==0){
            printf("saindo!\n");
        }
        else{
            printf("numero invalido!\n");
        }
        

    }
    return 0;
}
