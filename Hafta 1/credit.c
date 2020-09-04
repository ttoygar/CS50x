#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long no = get_long("Enter card number: \n");
    long num = no;
    int cnt = 0;
    int temp;
    long finnum = 0;
    int sum = 0;
    long first = no;
    
    do 
    {
        temp = num%10;
        finnum *= 10;
        if (cnt%2!=0)
        {
            finnum+=(temp*2);
        } else {
            finnum+=temp;
        }
        num /= 10;
        cnt ++;
    }
    while (num!=0);
    do
    {
        sum += finnum%10;
        finnum /= 10;
    } while(finnum!=0);
    while(first >=100)
    {
        first /=10;
    }
    if (sum%10!=0 || cnt<14){ printf("INVALID\n");}
    else{if(first/10 == 4){printf("VISA\n");}
    else{if(first == 34 || first == 37){printf("AMEX\n");}
    else{printf("MASTERCARD\n");}} }
}

