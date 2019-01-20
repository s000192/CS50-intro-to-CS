 else if (note[0] = D)
    {
        //shift to D
        f *= pow(2, 5/12);
        //octave change
        f *= pow(2, (note[-1] - 5));
        //sharp and flat
        if (note[1] = #)
        {
            f *= pow(2, 1/12);
        }
        else if (note[1] = b)
        {
            f *= pow(2, -1/12);
        }
        int m = round(f);
        return m;
    }

    else if (note[0] = E)
    {
        //shift to D
        f *= pow(2, 7/12);
        //octave change
        f *= pow(2, (note[-1] - 5));
        //sharp and flat
        if (note[1] = #)
        {
            f *= pow(2, 1/12);
        }
        else if (note[1] = b)
        {
            f *= pow(2, -1/12);
        }
        int m = round(f);
        return m;
    }

    else if (note[0] = F)
    {
        //shift to D
        f *= pow(2, 8/12);
        //octave change
        f *= pow(2, (note[-1] - 5));
        //sharp and flat
        if (note[1] = #)
        {
            f *= pow(2, 1/12);
        }
        else if (note[1] = b)
        {
            f *= pow(2, -1/12);
        }
        int m = round(f);
        return m;
    }

    else if (note[0] = G)
    {
        //shift to D
        f *= pow(2, 10/12);
        //octave change
        f *= pow(2, (note[-1] - 5));
        //sharp and flat
        if (note[1] = #)
        {
            f *= pow(2, 1/12);
        }
        else if (note[1] = b)
        {
            f *= pow(2, -1/12);
        }
        int m = round(f);
        return m;
    }
}