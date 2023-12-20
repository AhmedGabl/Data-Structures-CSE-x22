#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void heapify(int a[], int i, int size)
{
    int left = (2 * i) + 1, right = (2 * i) + 2, largest;

    if ((left <= size) && (a[left] > a[i]))
        largest = left;
    else
        largest = i;
    if ((right <= size) && (a[right] > a[largest]))
        largest = right;

    if (largest != i)
    {
        swap(a + i, a + largest);
        heapify(a, largest, size);
    }
}

void build_max_heap(int a[], int size)
{
    for (int i = size / 2; i >= 0; i--)
        heapify(a, i, size);
}

void heap_sort(int a[], int size)
{
    for (int i = size; i > 0; i--) 
    {
        swap(a,a+i);
        size--;
        heapify(a, 0, size);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Not Exist");
        return 0;
    }
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (n == 1)
    {
        printf("%d", a[0]);
        return 0;
    }
    build_max_heap(a, n - 1);
    heap_sort(a,n-1);
for (int  i = 0; i < n; i++)
{
    printf(" %d ",a[i]);
}
printf("\n");

    if (n % 2 == 1)
        printf("%d", a[n / 2 ]);
    else if ((a[n / 2 - 1] + a[n / 2]) % 2 == 0)
        printf("%d", (a[n / 2 - 1] + a[n / 2]) / 2);
    else
        printf("%0.1f", (a[n / 2 - 1] + a[n / 2]) / 2.0);

    return 0;
}