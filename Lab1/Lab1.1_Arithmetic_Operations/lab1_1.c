#include<stdio.h>

int main() 
{
    float arr[5];

    printf("Enter 5 numbers in order :");

        for(int i = 0 ; i < 5 ; i++ )
        {
            printf(" \n Enter the %d 's number : ",i+1);
            scanf("%f",(arr+i));
        }

    int temp1 , temp2 ;
    temp1 = temp2 = 0;
    float temp3 ,temp4 ;
    temp3 = temp4 = 0;

        for (int i =0 ; i < 5  ; i++ )
        {
            if (arr[i]<0)
                {
                    temp3 += arr[i];
                    temp1++;
                }
            else 
                {
                    temp4+=arr[i];
                    temp2++;
                }
        
        }

    temp3/=temp1;
    temp4/=temp2;

    printf("\n number of positive numbers : %d \n number of Negative numbers : %0.2d ", temp2,temp1 );
    printf("\n Average of Positive numbers %0.2f \n Average of Negative numbers %0.2f ", temp4, temp3);

    return 0 ;
}