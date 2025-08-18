void toh(int n, char src, char dest, char aux)
{
    if (n == 0)
        return;
    toh(n-1, src, aux, dest);
    printf("Move %d from %c to %c.\n", n, src, dest);
    toh(n-1, aux, dest, src);
}

int main()
{
    toh(2, 'A', 'C', 'B');
    return 0;
}