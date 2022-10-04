double func2(int *arrPtr)
{
    int sum = 0;
    int i;
    for (i = 0; i < 10; i++)
    {
        sum += *(arrPtr + i);
    }
    
    return (double)sum / 10;
}
