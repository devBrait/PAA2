/*
  Atividade feita em aula ->
  Vou ao cassino diariamente. Todo dia ganho uma certa quantia. Infelizmente a quantia é muitas
  vezes negativa. Meus amigos querem saber qual foi a sequência de dias, na minha história de
  idas ao cassino, em que meu ganho acumulado foi máximo. A tabela abaixo dá um exemplo para
  um período de 8 dias. Nesse exemplo, o ganho acumulado foi máximo ($35) no período que vai
  do dia 3 ao dia 6.
                               { 20 −30 15 −10 30 −20 −30 30 }
*/
#include <stdio.h>

int maxValue(int values[], int n)
{
  int greaterValue = values[0];
  int greaterTemp = values[0];

  for(int i = 1; i < n; i++)
  {
    if(values[i] > greaterTemp + values[i])
    {
      greaterTemp = values[i];
    }else
    {
      greaterTemp += values[i];
    }

    if(greaterTemp > greaterValue)
    {
      greaterValue = greaterTemp;
    }
  }
 
  return greaterValue;
}

int main(){
  
  int values[] =  {20, -30, 15, -10, 30, -20, -10, 30};
  int n = 8;
  
  int max = maxValue(values, n);

  printf("%d\n", max);
}