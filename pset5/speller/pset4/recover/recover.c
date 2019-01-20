#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    //ensure proper usage: only input the name of a forensic image
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    //open the forensic image
    FILE *raw_file = fopen(argv[1], "r");

    //ensure the forensic image can be opened
    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    //declare char *buffer
    unsigned char buffer[512] = {0};

    //declare integer n as the number of photos recovered
    int n = 0;

    //declare filename as char *
    char filename[8];

    FILE *img = NULL;

    //repeat until end of card using while loop
    while (fread(buffer, 512, 1, raw_file) == 1)
    {
        //read *file 512 bytes per time to buffer
        //fread(buffer, 512, 1, raw_file);

        //if the 512 bytes are the jpeg file header then
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //start of a new JPEG
            if (n > 0)
            {
                //close the previous file
                fclose(img);
            }

            //creating the filename of the jpeg
            sprintf(filename, "%03i.jpg", n);

            //open the jpeg file to be written
            img = fopen(filename, "w");

            //write the buffer to the jpeg file
            fwrite(buffer, 512, 1, img);

            n++;
        }

        //not the start of a JPEG
        else
        {
            //open the jpeg file to be written
            //img = fopen(filename, "w");
            if (img != NULL)
            {
                //write the buffer to the jpeg file
                fwrite(buffer, 512, 1, img);
            }
        }
    }

    //close raw file
    fclose(raw_file);

    //close image file
    fclose(img);
}