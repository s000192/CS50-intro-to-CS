#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //command line more than 1 or not number -> return 1
    if (argc != 2)
    {
        return 1;
    }
    else
    {
        //get key (using atoi)
        int k = atoi(argv[1]);

        //use remainder to get the key if k > 26
        k = k % 26;

        //get plaintext
        string p = get_string("plaintext: ");

        //declare string for ciphertext

        //encipher
        int i;
        int n;
        for (i = 0, n = strlen(p); i < n; i++)
        {
            // if char is alphabets, then execute the key
            if (isalpha(p[i]))
            {
                //encipher if it's uppercase letter
                if (isupper(p[i]))
                {
                    p[i] = (p[i] - 65 + k) % 26 + 65;
                }

                //encipher if it's lowercase letter
                else if (islower(p[i]))
                {
                    p[i] = (p[i] - 97 + k) % 26 + 97;
                }
            }

            //if char is not alphabets, then keep it
            else
            {
                p[i] = p[i];
            }
        }
        //print ciphertext
        printf("ciphertext: %s\n", p);
    }
}