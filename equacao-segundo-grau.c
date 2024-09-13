#include<stdio.h>
#include<stdlib.h>  
#include<math.h>
#include<stdbool.h>

void solucao(float Par_delta)
{
   if (Par_delta==0)
       printf("Raizes iguais!\n");
   else
       printf("Raizes diferentes!\n");
 
}
void resultado(float Par_delta)
{
       printf("\nDelta e igual a %.2f", Par_delta);
       printf("\n\nDelta Negativo, impossivel calcular.\n\n");
}
 
float CalcDelta(float a, float b, float c)
{
    float delta2;
    delta2 = pow(b,2)-4*a*c;
    printf("\nresultado dentro da função: %f", delta2);
    return delta2;
}
 
float entrarValor_a()
{
    float a;
    printf("\n\n\nInforme o valor de a:");
    scanf("%f", &a);
    return a;
}
 
float entrarValor_b()
{
    float b;
    printf("Informe o valor de b:");
    scanf("%f", &b);
    return b;
}
 
float entrarValor_c()
{
    float c;
    printf("Informe o valor de c:");
    scanf("%f", &c);
    return c;
}
 
float calcRaiz1(float a, float b, float delta)
{
    float x1;
    x1=((-b)+sqrt(delta))/(2*a);
    return x1;
}
 
float calcRaiz2(float a, float b, float delta)
{
    float x2;
    x2=((-b)-sqrt(delta))/(2*a);
    return x2;
}
 
bool checaDelta(float delta)
{
    if(delta<0)
    {
        resultado(delta);
        return false;
    }
    else
    {
        solucao(delta);
        return true;
    }  
}
 
void main()
{
   float a, b, c, delta, x1, x2, x;
    printf("\t\t\t\tResolucao da Equacao do Segundo Grau");
    a = entrarValor_a();
    b = entrarValor_b();
    c = entrarValor_c();
    delta=CalcDelta(a,b,c);
    if (checaDelta(delta))
    {
        x1 = calcRaiz1(a,b,delta);
        x2 = calcRaiz2(a,b,delta);
        printf("\nx1=%.2f e x2=%.2f\n\n",x1,x2);
    }
 
}