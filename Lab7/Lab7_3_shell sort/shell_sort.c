#include <stdio.h>
#include <stdlib.h>

void shell_sort(int* a ,int n);
void swap(int *i,int* j);

int main()
{
    int x , y;
    scanf("%d", &x);
    scanf("%d",&y);
    int arr[x];
    for (int  i = 0; i < x; i++)
    {
        scanf("%d", arr+i);
    }
shell_sort(arr,x);
printf("%d",arr[y-1]);
return 0;
}

void shell_sort(int* a ,int n)
{
    for (int i =n/2 ; i > 0; i /=2)
    {
        for (int j = i; j < n; j++)
        {
            for (int k =j - i; k>=0 ; k-=i)
            {
                if (*(a+k+i) <= *(a+k)) break;
                else
                {
                    swap((a+k),(a+k+i));
                }
                
            }
            
        }
        
    }
}

void swap(int *i,int* j)
{
    int temp = *j;
    *j= *i;
    *i= temp;
    
}