#include <stdio.h>
int tro(int *y, int *x){
     int troca;
     troca = (*y);
     *y = (*x);
     *x = troca;

}
int main()
{
    int a = 10, b = 5;
    printf("\nO  a = %d e o b = %d \n", a, b);
    tro(&a, &b);
    printf("\nO  a = %d e o b = %d \n", a, b);
    
    return 0;
}
