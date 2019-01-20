// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int n = fraction[0] - '0';
    if (fraction[2] == '8')
    {
        return n;
    }
    else if (fraction[2] == '4')
    {
        return n * 2;
    }
    else
    {
        return n * 4;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //declare frequency as double precision variable
    double f = 0.0;

    //switch through different notes
    if (note[0] == 'A')
    {
        f = 440.0;
    }

    //notes B
    else if (note[0] == 'B')
    {
        f = 440.0 * (pow(2.0, (2.0 / 12.0)));
    }

    //note C
    else if (note[0] == 'C')
    {
        f = 440.0 / (pow(2.0, (9.0 / 12.0)));
    }

    //note D
    else if (note[0] == 'D')
    {
        f = 440.0 / (pow(2.0, (7.0 / 12.0)));
    }


    //note E
    else if (note[0] == 'E')
    {
        f = 440.0 / (pow(2.0, (5.0 / 12.0)));
    }

    //note F
    else if (note[0] == 'F')
    {
        f = 440.0 / (pow(2.0, (4.0 / 12.0)));
    }

    //note G
    else if (note[0] == 'G')
    {
        f = 440.0 / (pow(2.0, (2.0 / 12.0)));
    }

    //shifting f for sharp and flat
    if (note[1] == '#')
    {
        f *= pow(2.0, (1.0 / 12.0));
    }

    else if (note[1] == 'b')
    {
        f /= pow(2.0, (1.0 / 12.0));
    }

    //split the octave
    int octave = note[strlen(note) - 1] - '0';

    //shifting through octaves
    f *= pow(2.0, (octave - 4.0));

    //round it to integer
    int m = round(f);
    return m;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
