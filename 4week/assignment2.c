#include<stdio.h>

int main()
{
    long fact=1;
    int n;

    printf("정수를 입력하시요 :");
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
    {
        fact*=i;
    }
    printf("%d! 은 %ld입니다.\n",n,fact);
    return 0;
    
}