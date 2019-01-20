// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    //declare n as char*
    char *n = argv[1];
    int m = atoi(n);

    //check if n is an int
    if (!isdigit(n[0]))
    {
        fprintf(stderr, "Usage: n should be a postive integer less than or equal to 100\n");
        return 2;
    }

    //ensure n is in the range between 0 and 100
    if(!((m > 0) && (m <= 100)))
    {
        fprintf(stderr, "Usage: n should be a postive integer less than or equal to 100\n");
        return 6;
    }

    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf_old;
    fread(&bf_old, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi_old;
    fread(&bi_old, sizeof(BITMAPINFOHEADER), 1, inptr);

    // determine outfile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf_new;
    bf_new = bf_old;

    // determine outfile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi_new;
    bi_new = bi_old;

    //creating new BITMAPINFOHEADER with scale m
    bi_new.biWidth = bi_old.biWidth * m;
    bi_new.biHeight = bi_old.biHeight * m;

    //keep track of the old padding
    int old_padding = (4 - (bi_old.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // determine padding for scanlines
    int new_padding = (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //update bisizeimage and bfsize for outfile
    bf_new.bfSize = 54 + (bi_new.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(bi_new.biHeight);
    bi_new.biSizeImage = bf_new.bfSize - 54;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf_old.bfType != 0x4d42 || bf_old.bfOffBits != 54 || bi_old.biSize != 40 ||
        bi_old.biBitCount != 24 || bi_old.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi_old.biHeight); i < biHeight; i++)
    {
        // each row will be printed out factor times
        int rowcounter = 0;

        while (rowcounter < m)
        {

            // iterate over pixels in scanline
            for (int j = 0; j < bi_old.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // each pixel will be printed out factor times
                int pixelcounter = 0;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                while (pixelcounter < m)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    pixelcounter++;
                }
            }

            // add new padding
            for (int k = 0; k < new_padding; k++)
                fputc(0x00, outptr);

            // seek back to the beginning of row in input file, but not after iteration of printing
            if (rowcounter < (m - 1))
                fseek(inptr, -(bi_old.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);

            rowcounter++;
        }

        // skip over padding, if any
        fseek(inptr, old_padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
