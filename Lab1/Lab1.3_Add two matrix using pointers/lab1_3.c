#include<stdio.h>

int main()
{
int temp1[3][3],temp2[3][3];
printf("separate column elemnts by spaces and press enter at it's end,\n ");

//input 1
printf("input matrix1 of size 3x3:\n");

    for (int i = 0 ; i <3 ; i++)
    {
        scanf("%d %d %d",*(temp1+i),*(temp1+i)+1,*(temp1+i)+2);
        printf("\n");
    }

//input 2
printf("input matrix2 of size 3x3:\n");
    for (int k = 0 ; k <3 ; k++)
    {
        scanf("%d %d %d",*(temp2+k),*(temp2+k)+1,*(temp2+k)+2);
        printf("\n");
    }

//suming and printing the out 
printf("sum of both matrices \n");

    for (int x = 0 ; x <3 ; x++)
    {
        for(int y = 0 ; y < 3 ; y++)
        {
            *(*(temp1+x)+y)  += *(*(temp2+x)+y);
             printf("%d   ",*(*(temp1+x)+y));
        }
        printf("\n\n");
    }

return 0;
}