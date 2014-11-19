#include <stdio.h>

const int big = 1050;

int data[big];

int f(int, int, int);

int main(){
    int n;
    scanf("%d", &n);

    int pos;
    scanf("%d", &pos);

    for(int i = 0;i < n;i++)
        scanf("%d", &data[i]);

    for(int delta = 0;delta < 10;delta++)
        printf("%d", f(pos, delta, n));
    printf("\n");
    return 0;
}

int f(int pos, int delta, int n){
    return data[(pos + delta) % n];
}
