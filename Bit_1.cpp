int setBits(int N)
{
    // Write Your Code here
    int count = 0, n;
    while (N)
    {
        if (N & 1)
            count++;
        N = N >> 1;
    }

    return count;
}