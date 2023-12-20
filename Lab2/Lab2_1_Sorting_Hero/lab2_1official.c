#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{

int arr1_size[2],arr2_size[2],t0=0;


//1st array
scanf("%d %d",arr1_size,arr1_size+1);
int arr[*(arr1_size)][*(arr1_size+1)];
int z_row_count[*(arr1_size)];

if(*arr1_size != *(arr1_size+1))
{
    printf("Not Valid");
    exit(1);
}

for (int i = 0; i < *arr1_size; i++)
{
    for (int j = 0; j < *(arr1_size+1); j++)
    {
        scanf("%d",(*(arr+i)+j));
        if(*(*(arr+i)+j))
            t0=0;
        else
            t0++;
        if(t0 == *(arr1_size+1))
            {
                *(z_row_count+i)=1;
                t0=0;
            }

    }
    t0=0;
}

//2nd array
scanf("%d %d",arr2_size,arr2_size+1);
int arr2[*(arr2_size)][*(arr2_size+1)];

if(*arr2_size <=0 || *(arr2_size+1)<=0)
{
    printf("Not Valid");
    exit(1);
}

//exception condition
if(*arr2_size != *(arr1_size+1))
{
    printf("Not Valid");
    exit(1);
}

int  z_column_count[*(arr2_size+1)];

for (int l = 0; l < *(arr2_size+1); l++)
{
    *(z_column_count+l)=0;
}

for (int x = 0; x < *arr2_size; x++)
{
    for (int y = 0; y < *(arr2_size+1); y++)
    {
        scanf("%d",(*(arr2+x)+y));
        if(!(*(*(arr2+x)+y)))
            (*(z_column_count+y) )++;
    }
}

int p_out[*(arr1_size)][*(arr2_size+1)];
int temp =0 ;

for (int fi = 0; fi < *(arr1_size); fi++)
{
    for (int ni = 0; ni <= *(arr2_size+1); ni++)
    {
        if(*(z_row_count+fi)==1)
        {
            *(*(p_out+fi)+ni)=0;
        }

        else if (((*(z_column_count+ni)))==(*(arr2_size)))
        {
            *(*(p_out+fi)+ni)=0;
        }

        else 
        {
           for (int sh = 0; sh < *(arr1_size+1); sh++)
           {
               temp += (*(*(arr+fi)+sh))*(*(*(arr2+sh)+ni));
           }
            *(*(p_out+fi)+ni) = temp;
            temp = 0;
        }
    }
}
/**
for (int k = 0; k < *(arr1_size); k++)
{
    printf("======<%d>",*(z_row_count+k));
}
printf("\n");
for (int k1 = 0; k1 < *(arr2_size+1); k1++)
{
    printf("======<%d>",*(z_column_count+k1));
}
printf("\n");
**/
for(int pr =0 ;pr < (*(arr1_size));pr++)
{
    for (int nt = 0; nt < (*(arr2_size+1)); nt++)
    {
        printf("%d ",*(*(p_out+pr)+nt));
    }
    printf("\n");
}
return 0;
}