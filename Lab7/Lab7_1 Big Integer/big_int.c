#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quicksort(long long unsigned int a[], int lo, int high);
void swap(long long unsigned int *i, long long unsigned int *j);
int is_bigger(long long unsigned int *i, long long unsigned int *j);

int main()
{
    int x, i;
    scanf("%d", &x);
    long long unsigned int a[x];
    for (i = 0; i < x; i++)
    {
        scanf("%lld", &a[i]);
    }
    quicksort(a, 0, x - 1);
    for (i = 0; i < x; i++)
    {
        printf("%lld ", a[i]);
        if (*a <= 0)
            break;
    }
    return 0;
}

void quicksort(long long unsigned int a[], int lo, int hi)
{
    int pivot, i, j;
    if (lo < hi)
    {
        pivot = lo;
        i = lo;
        j = hi;
        while (i < j)
        {
            while ((is_bigger(a + i, a + pivot) || a[i] == a[pivot]) && i <= hi)
            {
                i++;
            }
            while ((is_bigger(a + pivot, a + j)) && j >= lo)
            {
                j--;
            }
            if (i < j)
            {
                swap(a + i, a + j);
            }
        }
        swap(a + j, a + pivot);
        quicksort(a, lo, j - 1);
        quicksort(a, j + 1, hi);
    }
}

int is_bigger(long long unsigned int *i, long long unsigned int *j) // returns true case *i >*j
{
    int i_c = 0, j_c = 0;
    long long unsigned int i_t = *i, j_t = *j;
    while (i_t != 0)
    {
        i_c++;
        i_t /= 10;
    }
    while (j_t != 0)
    {
        j_c++;
        j_t /= 10;
    }
    if (i_c == j_c || i_c == 0 || j_c == 0)
        return (*i > *j);
    else
        return ((*i * (int)pow(10, j_c) + *j) > (*j * (int)pow(10, i_c) + *i));
}

void swap(long long unsigned int *i, long long unsigned int *j)
{
    long long unsigned int temp = *j;
    *j = *i;
    *i = temp;
}