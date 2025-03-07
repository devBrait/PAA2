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