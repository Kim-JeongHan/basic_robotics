#include<stdio.h>

int main()
{
    for(int i=1; i<10; i++)
    {
        printf("-----%d단-----\n", i);
        for(int j=1; j<10; j++)
        {
            printf("%d X %d = %d\n", i,j,i*j);
        }
    }
    return 0;
}