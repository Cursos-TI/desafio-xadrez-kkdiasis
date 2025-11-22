#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.
//Aluno: Cássio Assis

int main() {
    //contador
    int cont = 1;

    //MOVIMENTO DO BISPO
    printf("BISPO MOVE: \n");
    for(int i = 1; i <=5; i++){
        printf("DIRETA, CIMA (%i)\n", i);
    }
    
    //MOVIMENTO TORRE
    printf("\nTORRE MOVE: \n");

    while(cont <=5){
        printf("DIRETA (%i)\n", cont);
        cont++;
    }

    //resetando o contador
    cont = 1;


    //MOVIMENTO DA RAINHA 
    printf("\nRAINHA MOVE: \n");

    do
    {
        printf("ESQUERDA (%i)\n", cont);
        cont++;
        
    } while (cont <=8);
    
    
    


    return 0;
}
