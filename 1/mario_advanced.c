#include <cs50.h>
#include <stdio.h>

int input(void);


int main(void)
{
    int inp = input();
    for (int i = 1; i<(inp+1); i++)
    {
        for (int k = 0; k<(inp-i);k++)
        {
            printf(" ");
        }
        for (int j = 0; 0<(i-j); j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; 0<(i-j); j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}

int input(void)
{
    int inp;
    do 
    {
    inp = get_int("Enter a positive number between 1 and 8: \n");
    }
    while(inp>8 || inp<1);
    return inp;
}
