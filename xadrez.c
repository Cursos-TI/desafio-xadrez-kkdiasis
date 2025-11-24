#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
/*
    ### 🥇 Nível Mestre
Para o desafio final, as peças que utilizam loops simples terão seus códigos trocados por **funções recursivas**, e a movimentação do cavalo utilizará loops com variáveis múltiplas e/ou condições múltiplas, permitindo o uso de continue e break.

**Movimentação das Peças:**

**Bispo**: 5 casas na diagonal direita para cima
**Torre**: 5 casas para a direita
**Rainha**: 8 casas para a esquerda
**Cavalo**: 1 vez em L para cima à direita
Obs: É obrigatório o uso de loops aninhados na movimentação do bispo e funções recursivas.

*/

// DEFININDO UMA ESTRUTURA COMUM PARA TODAS AS PEÇAS.
typedef struct {
    char nome[10];
    char direcoesPermitidas[30];
    char direcao[30];
    char direcao2[30];
    int qtdMoves;
}Pecas;

void gameStart();
//PROTÓTIPO DE FUNCOES DE MOVIMENTAÇÃO DAS PEÇAS (funções estão na mesma ordem após o main):
//Movimentos da Rainha utilizando recursão>
void mvRainha(Pecas *p); 

void mvTorre(Pecas *p);

// CAVALO TEM MENU PROPRIO DE MOVIMENTO
void mvCavalo(Pecas *p);

// BISPO TEM MENU PROPRIO DE MOVIMENTO.
void mvBispo(Pecas *p);


//Menu para selecao de peças e movimento.
void gameStart(){
    
    Pecas peca;
    int selDir=0, selQuantMoves=0, selPeca=0;
    
    //MENU INICIAL PARA TODAS AS PEÇAS
    printf("\n\t\t==== CLI CHESS ====\n\n");
    printf("\tEscolha a peca que deseja mover:\n");
    printf("\t1) Rainha\n");
    printf("\t2) Torre\n");
    printf("\t3) Cavalo\n");
    printf("\t4) Bispo\n");
    
    printf("\tDigite o numero da peca que desja mover:");
    scanf("%d", &selPeca);
    
    switch (selPeca)
    {
        case 1 : strcpy(peca.nome, "RAINHA"); break;
        case 2 : strcpy(peca.nome, "TORRE"); break;
        case 3 : strcpy(peca.nome, "CAVALO"); break;
        case 4 : strcpy(peca.nome, "BISPO"); break;
        default: printf("\n\n\tOpcao Invalida! Reiniciando...\n\n"); gameStart(); return;
    }
    
    //NESTE BLOCO SEPARAM-SE BISPO E CAVALO POIS ELES TEM MENU A PARTIR PRÓPRIOS.
    if(strcmp(peca.nome, "BISPO") == 0){
        mvBispo(&peca); return;
    
    }else if(strcmp(peca.nome, "CAVALO") == 0){
        mvCavalo(&peca); return;
    
    }else{

        //MENU COMUM AS DEMAIS PEÇAS.
        printf("\n\tEscolha a direcao:\n");
        printf("\t1) Esquerda\n");
        printf("\t2) Direita\n");
        printf("\t3) Cima\n");
        printf("\t4) Baixo\n");
        printf("\tDigite o numero da direcao desejada:");
    
        scanf("%d", &selDir);
        
        switch (selDir)
        {
            case 1 : strcpy(peca.direcao, "ESQUERDA"); break;
            case 2 : strcpy(peca.direcao, "DIREITA"); break;
            case 3 : strcpy(peca.direcao, "CIMA"); break;
            case 4 : strcpy(peca.direcao, "BAIXO"); break;
            default: printf("\n\n\tOpcao Invalida! Reiniciando...\n\n"); gameStart(); return;
        }
                    
            printf("\n\tDigite a quantidade de casas: ");
            scanf("%d", &selQuantMoves);
            peca.qtdMoves = selQuantMoves;
            printf("\n\t%s MOVE %d CASAS PARA %s: \n", peca.nome, peca.qtdMoves, peca.direcao);
            mvRainha(&peca);
        
    }


    
    
    
 
}

int main (void){
    //COMEÇAR!!
    int jogar=1;
    gameStart();
    
    while(jogar == 1){
        printf("\n\tJogar novamente?\n1) Sim\n2) Sair ");
        printf("\nDigite numero da opcao: ");
        scanf("%d", &jogar);
        if(jogar == 1){
            gameStart();
        }else if(jogar < 1 || jogar > 2){
            printf("\n\tOpcao invalida!!!\n");
            jogar = 1;
        }
    }
    
    printf("Ate Logo!!");

    
        //FIM
    //BAI BAI

        return 0;
}


void mvRainha(Pecas *p){
    if(p->qtdMoves < 1)return;
        
    printf("%s: ",p->nome);
    printf("%s\n", p->direcao);
    p->qtdMoves--;

    mvRainha(p);
        
}

void mvTorre(Pecas *p){
       
    for(int i=p->qtdMoves;i > 0; i--){
        printf("%s: ",p->nome);
        printf("%s\n", p->direcao);
    }
}

void mvCavalo(Pecas *p){
    int selDir=0, move1=0, move2=0;

    //selecionar primeira direção do cavalo:
    printf("\n\tEscolha a direcao:\n");
    printf("\t1) Esquerda\n");
    printf("\t2) Direita\n");
    printf("\t3) Cima\n");
    printf("\t4) Baixo\n");
    printf("\tDigite o numero da direcao desejada:");
    scanf("%d", &selDir); 
        
    switch (selDir)
    {
        case 1 : strcpy(p->direcao, "ESQUERDA"); break;
        case 2 : strcpy(p->direcao, "DIREITA"); break;
        case 3 : strcpy(p->direcao, "CIMA"); break;
        case 4 : strcpy(p->direcao, "BAIXO"); break;
        default: printf("\n\n\tOpcao Invalida! Reiniciando...\n\n"); mvCavalo(p); return;
    }

    //selecionando a quantidade de casas do primeiro movimento:
    //caso 1 seja escolhido automaticamente o segundo movimento será 2 e vice-versa.
    printf("\n\tMovimento para %s (1 ou 2): ", p->direcao);
    scanf("%d", &move1);
    switch (move1)
    {
        case 1: move2 = 2; break;
        case 2: move2 = 1; break;
        default: printf("\n\n\tOpcao Invalida! Reiniciando...\n\n"); mvCavalo(p); return;
    }
    
    //Selecionando o segundo movimento, completando o l do cavalo
    //verificando as opcoes escolhidas previamente
    if((strcasecmp(p->direcao, "Esquerda") == 0) || (strcasecmp(p->direcao, "Direita") == 0)){
        printf("Finaliza movimento em: \n");
        printf("1) Cima\n2) Baixo\n");
        printf("Digite Opcao: ");
        scanf("%d", &selDir);
        switch (selDir)
        {
        case 1: strcpy(p->direcao2, "CIMA"); break;
        case 2: strcpy(p->direcao2, "BAIXO"); break;
        default: printf("\n\n\tOpcao Invalida! Reiniciando...\n\n"); mvCavalo(p); return;
        }

    }else{
        printf("Finaliza movimento em: \n");
        printf("1) Esquerda\n2) Direita\n");
        printf("Digite Opcao: ");
        scanf("%d", &selDir);
        switch (selDir)
        {
        case 1: strcpy(p->direcao2, "ESQUERDA"); break;
        case 2: strcpy(p->direcao2, "DIREITA"); break;
        default: printf("\n\n\tOpcao Invalida! Reiniciando...\n\n"); mvCavalo(p); return;
        }
    }

    printf("\n\t%s MOVE: %d CASAS PARA %s E %d CASA PARA %s\n", p->nome, move1, p->direcao, move2, p->direcao2);
    
    do{
        for(int i = move1; i > 0; i--){
            printf("%s: ",p->nome);
            printf("%s\n", p->direcao);
            move2--;
        }
        printf("%s: %s\n", p->nome, p->direcao2);
    }while(move2 > 0 );
}

void mvBispo(Pecas *p){
    int move1 = 1;
    int dir;

    printf("\n\tDigite o numero da direcao desejada:\n");
    printf("\t1) Diagonal Superior Esquerda\n");
    printf("\t2) Diagonal Superior Direita\n");
    printf("\t3) Diagonal Inferior Esquerda\n");
    printf("\t4) Diagonal Inferior Direita\n");
    printf("Movimento para: ");
    scanf("%d", &dir);

    switch (dir)
    {
        case 1: strcpy(p->direcao, "CIMA"); strcpy(p->direcao2, "ESQUERDA"); break;
        case 2: strcpy(p->direcao, "CIMA"); strcpy(p->direcao2, "DIREITA"); break;
        case 3: strcpy(p->direcao, "BAIXO"); strcpy(p->direcao2, "ESQUERDA"); break;
        case 4: strcpy(p->direcao, "BAIXO"); strcpy(p->direcao2, "DIREITA"); break;
        default: printf("\n\n\tOpcao Invalida! Reiniciando...\n\n"); mvBispo(p); return;
    }

    printf("Digite a quantidade de movimentos: ");
    scanf("%d", &move1);
    

    while(move1){
        for(int i=0; i<=move1; i++){
            printf("%s: %s ", p->nome, p->direcao);
            break;
        }
        printf("%s\n", p->direcao2);
        move1--;
    }
        
}



