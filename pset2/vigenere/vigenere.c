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
        //convert the alphabetical key to lowercase
        int l;
        int o;
        string k = argv[1];
        for (l = 0, o = strlen(k); l < o; l++)
        {
            if (isalpha(k[l]))
            {
                k[l] = tolower(k[l]);
            }
            else
            {
                return 1;
            }
        }

        //get plaintext
        string p = get_string("plaintext: ");

        //encipher
        int i;
        int j = 0;
        int n;
        int m;
        for (i = 0, n = strlen(p), m = strlen(k); i < n; i++)
        {
            // if char is alphabets, then execute the key
            if (isalpha(p[i]))
            {
                //encipher if it's uppercase letter
                if (isupper(p[i]))
                {
                    p[i] = (p[i] - 65 + k[j % m] - 97) % 26 + 65;
                }

                //encipher if it's lowercase letter
                else if (islower(p[i]))
                {
                    p[i] = (p[i] - 97 + k[j % m] - 97) % 26 + 97;
                }
                j = j + 1;
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