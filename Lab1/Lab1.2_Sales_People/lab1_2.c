#include<stdio.h>

int s_arr(int p[],int size);  //function to add the content of the array

int main()
{
int E_salary[9] = {0};
int temp;

do
{
    printf("\nEnter Employee gross sale (-1 to end):");
    scanf("%d",&temp);
    
    if (temp != -1)
    {
        temp = (temp*9/100)+200;
        printf("Employee salary is $ %d \n", temp );
    }
    else 
        break;

    if (temp >= 200 && temp < 300)
        E_salary[0] ++;
    else if (temp >= 300 && temp < 400)
        E_salary[1]++;
    else if (temp >= 400 && temp < 500)
        E_salary[2]++;
    else if (temp >= 500 && temp < 600)
        E_salary[3]++;
    else if (temp >= 600 && temp < 700)
        E_salary[4]++;
    else if (temp >= 700 && temp < 800)
        E_salary[5]++;
    else if (temp >= 800 && temp < 900)
        E_salary[6]++;
    else if (temp >= 900 && temp < 1000)
        E_salary[7]++;
    else if (1000 <= temp)
        E_salary[8]++;

}while(1);

printf("\n\nTotal %d Employees Reported \n \n",s_arr(E_salary,9));
printf("\n 200  299 : %d \n 300  399 : %d \n 400  499 : %d \n 500  599 : %d ",*(E_salary+0),*(E_salary+1),*(E_salary+2),*(E_salary+3));
printf("\n 600  699 : %d \n 700  799 : %d \n 800  899 : %d \n 900  999 : %d \n over 1000: %d",*(E_salary+4),*(E_salary+5),*(E_salary+6),*(E_salary+7),*(E_salary+8));

return 0;
}

int s_arr(int p[],int size)
{ 
int temp=0;
    for(int i=0 ; i< size;i++)
    { 
        temp+= p[i];
    }
return temp;
}
