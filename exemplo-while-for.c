//contador sniff, o ratinho

#include <stdio.h>
#include<stdlib.h>
int main() 
{
    int contador = 0;
    while(contador <=1000){
        printf("sniff, o ratinho %d\n", contador);
        contador++;
    }
    printf("sniff, o ratinho total: %d\n", contador);
return 0;
}

//contagem regressiva sniff, o ratinho

#include <stdio.h>
#include<stdlib.h>
int main() 
{
    int contador = 1000;
    while(contador > 0){
        printf("sniff, o ratinho %d\n", contador);
        contador--;
    }
    printf("sniff, o ratinho total: %d\n", contador);
return 0;
}

//conta a partir do numero de letras sniff, o ratinho

#include <stdio.h>
#include<stdlib.h>
int main() 
{
    int contador = 0;
    char letra;
    while(letra=getchar() != 'q')
    {
        printf("sniff, o ratinho %d\n", contador);
        fflush(stdin);
        contador++;
    }
    printf("sniff, o ratinho total: %d\n", contador);
    printf("parando... \n");
    
    return 0;
}

//senha do Sniff, o ratinho

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void main() 
{
  char senha[20];
  for(int x=1;x<=3;++x)
  {
      printf("Digite a senha: ");
      gets(senha);
      if(strcmp(senha,"Sniff, o ratinho")==0)
      {
          printf("OK! \n");
          break;
      }
      else
      {
          printf("Tente novamente! \n");
      }
      printf("Tentativa: %d \n", x);
  }
}

// FUSÃO SNIFF, O RATINHO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
int main() {
    char senha[20];
    bool senha_correta = false; // Inicializa como falso
 
    for (int x = 1; x <= 3; ++x) {
        printf("Digite a senha: ");
        fgets(senha, sizeof(senha), stdin); // Lê a senha com segurança
       
        if (strcmp(senha, "Sniff, o ratinho\n") == 0) {
            printf("OK! \n");
            senha_correta = true; // Define como verdadeiro
            break;
        } else {
            printf("Tente novamente! \n");
        }
        printf("Tentativa: %d \n", x);
    }
 
    if (senha_correta) { // Verifica se a senha está correta
        int contador = 0;
        char letra;
        while ((letra = getchar()) != 'q') {
            printf("sniff, o ratinho %d\n", contador);
            contador++;
        }
        printf("sniff, o ratinho total: %d\n", contador);
        printf("parando... \n");
    } else {
        printf("Senha incorreta. Programa encerrado.\n");
    }
 
    return 0;
}
