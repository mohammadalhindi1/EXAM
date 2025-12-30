void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    unsigned int y;
    int tmp;

    while (i < size)
    {
        y = i;
        while (y < size)
        {
            if (tab[y] < tab[i])
            {
                tmp = tab[y];
                tab[y] = tab[i];
                tab[i] = tmp;
            }
            y++;
        }
        i++;
    }
    
}
