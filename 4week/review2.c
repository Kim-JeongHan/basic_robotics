#include<stdio.h>

//input 9

int main(void)
{
    int n;
    int i = 1;
    printf("출력하고싶은단: ");
    scanf("%d", &n);
    while(i<= 9)
    {
        printf("%d*%d = %d \n", n, i, n*i);
        i++;
    }
    return 0;
}