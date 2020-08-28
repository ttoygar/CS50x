#include <cs50.h>
#include <stdio.h>

//int number_positive();

int main(void){
    int number;
    do
    {
        number = get_int(" height : ");
       
    }
    while (number < 1 || number>8);
    
    for (int i = 0; i < number; i++)
  
    {
        for (int k = number - i ; k > 0 ; k--){
             printf(" ");
      }

      for (int j = 0; j <= i; j++)

      {

          printf("#");

      }

      printf("\n");

  }

}