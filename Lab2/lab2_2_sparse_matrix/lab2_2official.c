#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sort_arr(int *p,int size);
unsigned find_pairs(int *h,int i,int*ta , int t);

int main() {
    unsigned i,t,out;
    scanf("%d",&i);
    scanf("%d",&t);

    unsigned h[i],ta[t];
    for (int i1 = 0; i1 < i; i1++)
    {
        scanf("%d",h+i1);
    }
    sort_arr(h,i);
    for (int i2 = 0; i2 < t; i2++)
    {
        scanf("%d",ta+i2);
    }
    sort_arr(ta,t);
    
    out = find_pairs(h,i,ta,t);
    /**
    for(int a=0;a<i;a++)
    {
        printf(" %d ",*(h+a));
    }
    for(int a1=0;a1< t;a1++)
    {
        printf(" %d ",*(ta+a1));
    }
    **/
    printf("%d",out);
    return 0;
}


void sort_arr(int *p,int size )
{
    int temp=0;
for (int i = 0; i < size-1; i++)
{
    for (int j = 0; j < size-i-1; j++)
    {
        if (*(p+j)>*(p+j+1))
        {
            temp = *(p+j);
            *(p+j)=*(p+j+1);
            *(p+j+1)=temp;
        }
    }
}
}
unsigned find_pairs(int *h,int i,int*ta , int t)
{
    unsigned temp1=0,temp=0;

for (int a = 0; a < i; a++)
{
    for (int i1 = temp1 ; i1 < t ;)
    {
        if(*(h+a) >= *(ta+i1))
        {   
            temp1=i1+1;
//        printf("======>%d took %d ",*(h+a),*(ta+i1));
            temp++;
            break;
        }
        else 
           i1++;
    }
}
return temp;
}