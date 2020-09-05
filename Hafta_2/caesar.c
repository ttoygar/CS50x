#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string transform(string entry, int num);
int main(int argc, string argv[])
{
    // Creates variable "check" to check if any chars of "key" is not digit
    int check = 0;
    if (argc !=2)
    {
        return 1;
    }
    else
    {
        for (int i=0,n=strlen(argv[1]);i<n;i++)
        {
            if (isdigit(argv[1][i]) ==0)
            {
                check++;
            }
        }
    }
    // there should be only 1 entry after program name and that entry should consist only digits
    if(argc==2 && check==0)
    {
        // change the key to int
        int num = atoi(argv[1]);
        string entry = get_string("plaintext: ");
        string exit = transform(entry,num);
        printf("ciphertext: %s\n",exit);
    } else {
        printf("Usage: ./caesar key\n");
    }
}

string transform(string entry, int num)
{
    for (int i=0, n=strlen(entry); i<n; i++)
    
    {
        if(65<=entry[i] && entry[i]<=90)
        {
            if(entry[i]+num > 90)
            {
                entry[i] = ((entry[i]-65+num)%26) +65;
            } else {
                entry[i] = entry[i]+num;
            }
               
        } else 
        {
            if (97<=entry[i] && entry[i]<=122)
            {
                if((entry[i]+num)>122)
                {                
                entry[i] = ((entry[i]-97+num)%26) +97;                
                } else{
                    entry[i] = entry[i]+num;                    
                }
            }
        }
    }    
    return entry;
}

