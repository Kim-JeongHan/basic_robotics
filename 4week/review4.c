#include<stdio.h>


int main(void)
{
    int x, y;
    for(y = 1; y <= 5; y++)
    {
        for(x = 0; x < y; x++)
            printf("*");
        printf("\n");
        // 내부반복문이종료될때마다실행
    }
    return 0;
}