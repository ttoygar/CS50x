#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float num_fl = get_float("Enter the amount: \n");
    int num = round(num_fl * 100);
    int cnt = 0;
    while (num >= 25){num-=25; cnt+=1;};
    while (num >= 10){num-=10; cnt+=1;};
    while (num >= 5){num-=5; cnt+=1;};
    while (num >= 1){num-=1; cnt+=1;};
   
    printf("%i\n",cnt);
}
