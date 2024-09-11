#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int mynum, usernum; //variável para número
    srand(time(NULL)); //utiliza o relógio interno do computador para controlar a escolha da semente
    mynum = rand() %10;
    printf("Adivinhe o número (0 - 9)\n");
    
    while(1){
        printf("Adivinhe o número: ");
        scanf("%d", &usernum);
        
        if (mynum == usernum) {
            printf("Acertou!");
            break;
        }
        else if (mynum > usernum){
            printf("Meu número é maior que %d. Tente de novo.\n\n", usernum);
        }
        else{
            printf("Meu número é menor que %d. Tente de novo.\n\n", usernum);
        }
    }
    
    return 0;
}