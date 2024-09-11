//lista de exercícios

//exercício 1
#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;
    printf("digite primeiro número: ");
    scanf("%d", &a);
    printf("digite segundo número: ");
    scanf("%d", &b);
    if (a>b){
       printf ("imprimir o maior: %d", a);
    }
        else{
         printf ("imprimir o maior: %d", b);
        }
        return 0;
}

//exercício 2
#include <stdio.h>
#include <stdlib.h>

int main(){
    float a;
    printf("digite o número: ");
    scanf("%f", &a);
    
    if(a<0){
        printf("numero negativo");
    }
        else{
            printf("numero positivo");
        }
        return 0;
}

//exercício 3
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char genero;
    printf("digite f ou m: ");
    scanf("%c", &genero);
    
    if(genero=='f'){
        printf("feminino", genero);
    }
    else if(genero=='m'){
        printf("masculino", genero);
    }
            else{
                printf("invalido");
            }
    
        return 0;
}

//exercício 4
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char letra;
    printf("digite uma letra: ");
    scanf("%c", &letra);
    
    if(letra=='a' || letra=='e' || letra=='i' || letra=='o' || letra=='u'){
        printf("é vogal", letra);
    }
            else{
                printf("é consoante", letra);
            }
    
        return 0;
}

//exercício 5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    float media, nota1, nota2;
    
    printf("digite primeira nota: ");
    scanf("%f", &nota1);
    printf("digite segunda nota: ");
    scanf("%f", &nota2);
    media = (nota1 + nota2)/2;
    
    if(media<7){
        printf("Reprovado, sua média é %.1f\n", media);
    }
    else if(media==10){
        printf("Aprovado com distinção, sua média é %.1f\n", media);
    }
    else{
        printf("Aprovado, sua média é %.1f\n", media);
    }
    
        return 0;
}

//exercício 6
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int a, b, c;
    
    printf("digite primeiro numero: ");
    scanf("%d", &a);
    printf("digite segundo numero: ");
    scanf("%d", &b);
    printf("digite terceiro numero: ");
    scanf("%d", &c);
    
    if(a>b && a>c){
        printf("maior numero é %d", a);
    }
    else if(b>a && b>c){
        printf("maior numero é %d", b);
    }
    else{
        printf("maior numero é %d", c);
    }
    
        return 0;
}

//exercício 7
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int a, b, c;
    
    printf("digite primeiro numero: ");
    scanf("%d", &a);
    printf("digite segundo numero: ");
    scanf("%d", &b);
    printf("digite terceiro numero: ");
    scanf("%d", &c);
    
    if(a>b && a>c){
        printf("maior numero é %d", a);
    }
    else if(b>a && b>c){
        printf("maior numero é %d", b);
    }
    else{
        printf("maior numero é %d", c);
    }
    
    if(a<b && a<c){
        printf("\tmenor numero é %d", a);
    }
    else if(b<a && b<c){
        printf("\tmenor numero é %d", b);
    }
    else{
        printf("\tmenor numero é %d", c);
    }
    
        return 0;
}

//exercício 8
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int a, b, c;
    
    printf("digite primeiro preço: ");
    scanf("%d", &a);
    printf("digite segundo preço: ");
    scanf("%d", &b);
    printf("digite terceiro preço: ");
    scanf("%d", &c);
    
    if(a<b && a<c){
        printf("compre esse pelo menor preço: %d", a);
    }
    else if(b<a && b<c){
        printf("compre esse pelo menor preço: %d", b);
    }
    else{
        printf("compre esse pelo menor preço: %d", c);
    }
    
        return 0;
}

//exercício 9
#include <stdio.h>
 
int main() {
    int num1, num2, num3, aux; //aux é espaço temporário pra armazenar o valor durante a troca de 2 números
 
    printf("Digite três números: ");
    scanf("%d %d %d", &num1, &num2, &num3);
 
    if (num1 < num2) {
        aux = num1;
        num1 = num2;
        num2 = aux;
    }
 
    if (num1 < num3) {
        aux = num1;
        num1 = num3;
        num3 = aux;
    }
 
    if (num2 < num3) {
        aux = num2;
        num2 = num3;
        num3 = aux;
    }
    
    printf("Números em ordem decrescente: %d %d %d\n", num1, num2, num3);
 
    return 0;
}

//ecercicio 10
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char turno;
    printf("digite seu turno (M, V ou N): ");
    scanf("%c", &turno);
    
    if(turno=='m'){
        printf("bom dia", turno);
    }
    else if(turno=='v'){
        printf("boa tarde", turno);
    }
    else if(turno=='n'){
        printf("boa noite", turno);
    }
            else{
                printf("invalido");
            }
    
        return 0;
}